#include <iostream>
using namespace std;

struct IntBuffer {
    int* data = nullptr;
    int size = 0;
    int capacity = 0;
};

void reserve(IntBuffer& b, int newCapacity) {
    if (newCapacity <= b.capacity) return;

    int* larger = new int[newCapacity];
    for (int i = 0; i < b.size; ++i)
        larger[i] = b.data[i];

    delete[] b.data;
    b.data = larger;
    b.capacity = newCapacity;
}

void ensureCapacity(IntBuffer& b) {
    if (b.size < b.capacity) return;
    int newCapacity = (b.capacity == 0) ? 1 : b.capacity * 2;
    reserve(b, newCapacity);
}

bool insertAt(IntBuffer& b, int pos, int value) {
    if (pos < 0 || pos > b.size) return false;

    ensureCapacity(b);

    for (int i = b.size; i > pos; --i)
        b.data[i] = b.data[i - 1];

    b.data[pos] = value;
    ++b.size;
    return true;
}

bool deleteAt(IntBuffer& b, int pos) {
    if (pos < 0 || pos >= b.size) return false;

    for (int i = pos; i < b.size - 1; ++i)
        b.data[i] = b.data[i + 1];

    --b.size;
    return true;
}

bool updateAt(IntBuffer& b, int pos, int value) {
    if (pos < 0 || pos >= b.size) return false;
    b.data[pos] = value;
    return true;
}

int search(const IntBuffer& b, int value) {
    for (int i = 0; i < b.size; ++i)
        if (b.data[i] == value)
            return i;
    return -1;
}

void reverse(IntBuffer& b) {
    int left = 0, right = b.size - 1;
    while (left < right) {
        int temp = b.data[left];
        b.data[left] = b.data[right];
        b.data[right] = temp;
        ++left;
        --right;
    }
}

void display(const IntBuffer& b) {
    cout << "[ ";
    for (int i = 0; i < b.size; ++i)
        cout << b.data[i] << " ";
    cout << "]\n";
}

void statistics(const IntBuffer& b) {
    if (b.size == 0) {
        cout << "Array is empty.\n";
        return;
    }

    int sum = 0, mn = b.data[0], mx = b.data[0], even = 0;

    for (int i = 0; i < b.size; ++i) {
        sum += b.data[i];
        if (b.data[i] < mn) mn = b.data[i];
        if (b.data[i] > mx) mx = b.data[i];
        if (b.data[i] % 2 == 0) ++even;
    }

    cout << "Sum: " << sum << '\n';
    cout << "Minimum: " << mn << '\n';
    cout << "Maximum: " << mx << '\n';
    cout << "Even count: " << even << '\n';
}

void printState(const IntBuffer& b) {
    cout << "Data: ";
    display(b);
    cout << "Size: " << b.size
         << ", Capacity: " << b.capacity << '\n';
}

void destroy(IntBuffer& b) {
    delete[] b.data;
    b.data = nullptr;
    b.size = 0;
    b.capacity = 0;
}

int main() {
    IntBuffer b;

    insertAt(b, 0, 20);
    insertAt(b, 1, 30);
    insertAt(b, 0, 10);

    cout << "Initial data:\n";
    printState(b);

    cout << "\nInsert 25 at position 2:\n";
    insertAt(b, 2, 25);
    printState(b);

    cout << "\nUpdate position 1 to 99:\n";
    updateAt(b, 1, 99);
    printState(b);

    cout << "\nSearch for 30: index = "
         << search(b, 30) << '\n';

    cout << "\nReverse:\n";
    reverse(b);
    printState(b);

    cout << "\nDelete last element:\n";
    deleteAt(b, b.size - 1);
    printState(b);

    cout << "\nStatistics:\n";
    statistics(b);

    destroy(b);
    return 0;
}
