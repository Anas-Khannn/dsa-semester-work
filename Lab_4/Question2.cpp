/******************************************************************************
 *  Lab 4 - Question 2
 *  Lock-Free Bounded Queue (Multi-Producer / Multi-Consumer Ring Buffer)
 *
 *  Requirements satisfied:
 *    1. Lock-freedom ....... no std::mutex / lock / condition_variable anywhere.
 *                            Progress only depends on std::atomic CAS.
 *    2. Memory efficiency .. false sharing avoided by putting the read head
 *                            and the write head on SEPARATE cache lines.
 *    3. Optimized ordering .. no std::memory_order_seq_cst in the hot path.
 *                            relaxed for index arithmetic, acquire/release for
 *                            the per-slot "sequence" hand-off.
 *    4. API ................ LockFreeQueue<T, Capacity>
 *                              bool enqueue(const T& item);
 *                              bool dequeue(T& item);
 *
 *  Algorithm: Dmitry Vyukov's bounded MPMC queue.
 *  Every slot owns an atomic "sequence" number. A slot is usable by a producer
 *  only when sequence == ticket, and usable by a consumer only when
 *  sequence == ticket + 1. This single atomic per slot replaces any lock.
 *
 *  Compile:  g++ -std=c++17 -O2 -pthread Question2.cpp -o Question2
 ******************************************************************************/

#include <atomic>
#include <chrono>
#include <cstddef>
#include <iostream>
#include <new>
#include <thread>
#include <utility>
#include <vector>

// ---------------------------------------------------------------------------
// Cache line size used for padding. 64 bytes is the de-facto standard on
// x86/x64 and is safe on ARM (64 or 128 bytes -- we simply pad to the smaller).
// ---------------------------------------------------------------------------
static constexpr std::size_t kCacheLineSize = 64;

template <typename T, std::size_t Capacity>
class LockFreeQueue {
    // -----------------------------------------------------------------------
    // Compile time sanity checks
    // -----------------------------------------------------------------------
    static_assert(Capacity >= 2, "LockFreeQueue: Capacity must be at least 2");
    static_assert((Capacity & (Capacity - 1)) == 0,
                  "LockFreeQueue: Capacity must be a power of two");

public:
    using value_type = T;
    static constexpr std::size_t capacity = Capacity;

    // -----------------------------------------------------------------------
    // One ring-buffer slot. Raw (aligned) storage is used so that T needs no
    // default constructor: the object is created in place by enqueue() and
    // destroyed explicitly by dequeue() / the destructor.
    // -----------------------------------------------------------------------
    struct Cell {
        std::atomic<std::size_t> sequence;   // the "ticket" of this slot
        alignas(T) unsigned char storage[sizeof(T)];
    };

    // Cache-line isolated atomic index (kills false sharing).
    struct alignas(kCacheLineSize) IsolatedIndex {
        std::atomic<std::size_t> value;
    };

    LockFreeQueue() noexcept {
        // Slot i starts out expecting ticket i -> producers may fill it.
        for (std::size_t i = 0; i < Capacity; ++i) {
            buffer_[i].sequence.store(i, std::memory_order_relaxed);
        }
        head_.value.store(0, std::memory_order_relaxed);
        tail_.value.store(0, std::memory_order_relaxed);
    }

    // Single threaded by definition at destruction time: everything between
    // head and tail is still alive and must be destroyed.
    ~LockFreeQueue() {
        const std::size_t head = head_.value.load(std::memory_order_relaxed);
        const std::size_t tail = tail_.value.load(std::memory_order_relaxed);
        for (std::size_t pos = head; pos != tail; ++pos) {
            reinterpret_cast<T*>(buffer_[pos & kMask].storage)->~T();
        }
    }

    // A ring buffer owns its storage -> copying/moving it is meaningless.
    LockFreeQueue(const LockFreeQueue&) = delete;
    LockFreeQueue& operator=(const LockFreeQueue&) = delete;

    // =======================================================================
    // PRODUCER SIDE
    // =======================================================================

    // Required API: push an item, return false when the queue is full.
    bool enqueue(const T& item) { return emplace(item); }

    // Convenience overload so rvalues are moved instead of copied.
    bool enqueue(T&& item) { return emplace(std::move(item)); }

    // =======================================================================
    // CONSUMER SIDE
    // =======================================================================

    // Required API: pop into item, return false when the queue is empty.
    bool dequeue(T& item) {
        Cell* cell   = nullptr;
        std::size_t pos = head_.value.load(std::memory_order_relaxed);

        for (;;) {
            cell = &buffer_[pos & kMask];

            // acquire: synchronises-with the release store of the producer that
            // last freed this slot, so the slot is genuinely ours to refill.
            const std::size_t seq = cell->sequence.load(std::memory_order_acquire);
            const std::ptrdiff_t diff =
                static_cast<std::ptrdiff_t>(seq) - static_cast<std::ptrdiff_t>(pos + 1);

            if (diff == 0) {
                // relaxed: this CAS only arbitrates WHO owns this position.
                // It does not publish any data, so no ordering is needed here.
                if (head_.value.compare_exchange_weak(pos, pos + 1,
                                                      std::memory_order_relaxed,
                                                      std::memory_order_relaxed)) {
                    break;
                }
                // CAS failed: another consumer won, pos was refreshed for us.
            } else if (diff < 0) {
                return false;                       // slot not filled yet -> EMPTY
            } else {
                // Another consumer moved ahead; re-read and retry.
                pos = head_.value.load(std::memory_order_relaxed);
            }
        }

        T* element = reinterpret_cast<T*>(cell->storage);

        // relaxed read of the element: the acquire above already ordered it
        // after the producer's write, no extra fence required.
        item = std::move(*element);
        element->~T();

        // release: hands the slot back to the producer of the next lap.
        // This store is the single "publish" point of the whole algorithm.
        cell->sequence.store(pos + kMask + 1, std::memory_order_release);
        return true;
    }

    // =======================================================================
    // Introspection helpers
    // =======================================================================
    static constexpr std::size_t getCapacity() { return Capacity; }

    bool empty() const {
        return head_.value.load(std::memory_order_acquire) >=
               tail_.value.load(std::memory_order_acquire);
    }

    std::size_t sizeApprox() const {
        const std::size_t t = tail_.value.load(std::memory_order_acquire);
        const std::size_t h = head_.value.load(std::memory_order_acquire);
        return (t > h) ? (t - h) : 0;              // racy by nature, estimate only
    }

    // True when the platform can compile std::atomic<size_t> without a lock.
    static bool atomicsAreLockFree() {
        return std::atomic<std::size_t>{}.is_lock_free();
    }

private:
    static constexpr std::size_t kMask = Capacity - 1;   // Capacity is 2^n

    // Private core of enqueue(); forwarding reference covers both overloads.
    template <typename U>
    bool emplace(U&& item) {
        Cell* cell   = nullptr;
        std::size_t pos = tail_.value.load(std::memory_order_relaxed);

        for (;;) {
            cell = &buffer_[pos & kMask];

            // acquire: pairs with the consumer's release store, guaranteeing the
            // previous lap's object was already destroyed before we overwrite it.
            const std::size_t seq = cell->sequence.load(std::memory_order_acquire);
            const std::ptrdiff_t diff =
                static_cast<std::ptrdiff_t>(seq) - static_cast<std::ptrdiff_t>(pos);

            if (diff == 0) {
                // relaxed: pure arbitration of the ticket, no data published.
                if (tail_.value.compare_exchange_weak(pos, pos + 1,
                                                      std::memory_order_relaxed,
                                                      std::memory_order_relaxed)) {
                    break;
                }
            } else if (diff < 0) {
                return false;                       // still occupied -> FULL
            } else {
                pos = tail_.value.load(std::memory_order_relaxed);
            }
        }

        // Construct in place. relaxed: we own this slot exclusively.
        new (cell->storage) T(std::forward<U>(item));

        // release: publish the constructed object to whichever consumer
        // acquires this sequence value next. This is the synchronisation point.
        cell->sequence.store(pos + 1, std::memory_order_release);
        return true;
    }

    // ------------------------------------------------------------------------
    // THE ONLY TWO SHARED MUTABLE COUNTERS.
    // Each lives in its own cache-line aligned block, so producers hammering
    // tail_ never invalidate the cache line holding head_ (and vice versa).
    // This is the classic false-sharing fix.
    // ------------------------------------------------------------------------
    alignas(kCacheLineSize) IsolatedIndex head_;   // consumer side (dequeue)
    alignas(kCacheLineSize) IsolatedIndex tail_;   // producer side (enqueue)

    // Buffer aligned to a cache line as well, so slot 0 / slot N-1 never share
    // a line with the indices or with any other object.
    alignas(kCacheLineSize) Cell buffer_[Capacity];
};

// ===========================================================================
// DEMONSTRATION / STRESS TEST  (4 producers + 4 consumers)
// ===========================================================================
int main() {
    using Queue = LockFreeQueue<int, 1024>;   // power of two, as required

    constexpr int kProducers        = 4;
    constexpr int kConsumers        = 4;
    constexpr int kItemsPerProducer = 250000;

    Queue queue;

    std::cout << "=== Lock-Free Bounded Queue (MPMC Ring Buffer) ===\n";
    std::cout << "Capacity            : " << Queue::getCapacity() << "\n";
    std::cout << "Producers           : " << kProducers << "\n";
    std::cout << "Consumers           : " << kConsumers << "\n";
    std::cout << "Items per producer  : " << kItemsPerProducer << "\n";
    std::cout << "Total items         : " << kProducers * kItemsPerProducer << "\n";
    std::cout << "size_t atomic       : "
              << (Queue::atomicsAreLockFree() ? "lock-free" : "NOT lock-free") << "\n\n";

    std::atomic<long long> consumedCount(0);
    std::atomic<long long> consumedSum(0);

    const auto start = std::chrono::steady_clock::now();

    // ---- producers ---------------------------------------------------------
    std::vector<std::thread> producers;
    producers.reserve(kProducers);
    for (int p = 0; p < kProducers; ++p) {
        producers.emplace_back([&queue, p]() {
            for (int i = 0; i < kItemsPerProducer; ++i) {
                const int value = p * 1000000 + i;      // unique per item
                // Spin until there is room (the queue itself never blocks).
                while (!queue.enqueue(value)) {
                    std::this_thread::yield();
                }
            }
        });
    }

    // ---- consumers ---------------------------------------------------------
    std::vector<std::thread> consumers;
    consumers.reserve(kConsumers);
    for (int c = 0; c < kConsumers; ++c) {
        consumers.emplace_back([&queue, &consumedCount, &consumedSum]() {
            int item = 0;
            while (true) {
                if (queue.dequeue(item)) {
                    consumedCount.fetch_add(1, std::memory_order_relaxed);
                    consumedSum.fetch_add(item, std::memory_order_relaxed);
                } else if (consumedCount.load(std::memory_order_relaxed) >=
                           static_cast<long long>(kProducers) * kItemsPerProducer) {
                    break;                            // work is done
                } else {
                    std::this_thread::yield();        // momentarily empty
                }
            }
        });
    }

    for (auto& t : producers) t.join();
    for (auto& t : consumers) t.join();

    const auto end = std::chrono::steady_clock::now();
    const double seconds =
        std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

    // ---- expected result ---------------------------------------------------
    const long long expectedCount = static_cast<long long>(kProducers) * kItemsPerProducer;
    long long expectedSum = 0;
    for (int p = 0; p < kProducers; ++p) {
        for (int i = 0; i < kItemsPerProducer; ++i) {
            expectedSum += static_cast<long long>(p) * 1000000 + i;
        }
    }

    const long long count = consumedCount.load(std::memory_order_relaxed);
    const long long sum   = consumedSum.load(std::memory_order_relaxed);

    std::cout << "Elapsed             : " << seconds << " s\n";
    std::cout << "Throughput          : " << static_cast<long long>(count / seconds)
              << " items/s\n\n";
    std::cout << "Items consumed      : " << count << " (expected " << expectedCount << ")\n";
    std::cout << "Sum of values       : " << sum << " (expected " << expectedSum << ")\n";
    std::cout << "Remaining in queue  : " << queue.sizeApprox() << "\n\n";

    const bool ok = (count == expectedCount) && (sum == expectedSum) && queue.empty();
    std::cout << (ok ? "RESULT: PASS - no item lost, duplicated or corrupted.\n"
                     : "RESULT: FAIL\n");

    return ok ? 0 : 1;
}