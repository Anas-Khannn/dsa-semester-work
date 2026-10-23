#include <iostream>
using namespace std;

/*
    Practice Question 5 (Linked List)

    Detect whether a singly linked list contains a loop (cycle) and,
    if it does, remove the loop so the list becomes a normal list again.

    Example:
        Input : 1 -> 2 -> 3 -> 4 -> 5 -> 6
                                 ^         |
                                 |_________|      (6 points back to 3)
        Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
                "Loop detected at node 3" and the loop is removed.

    Approach:
        1. Floyd's cycle detection: slow moves one step, fast moves two.
           If they meet, a loop exists.
        2. Reset slow to head and move both one step at a time.
           Where they meet again is the first node of the loop.
        3. Walk to the node whose next is that first node and set
           its next to NULL, which breaks the loop.
*/

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Returns the first node of the loop, or NULL if there is no loop
Node* detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop found; find its first node
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

bool removeLoop(Node* head) {
    Node* loopStart = detectLoop(head);
    if (loopStart == NULL) {
        return false;
    }

    if (loopStart == head) {
        // The loop starts at head, so walk to the last node
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = NULL;
        return true;
    }

    // Step back to the node just before the loop start
    Node* temp = loopStart;
    while (temp->next != loopStart) {
        temp = temp->next;
    }
    temp->next = NULL;
    return true;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Node* head = NULL;
    for (int i = 1; i <= 6; i++) {
        insertAtEnd(head, i);
    }

    // Create a loop: last node (6) points back to node 3
    Node* third = head;
    for (int i = 0; i < 2; i++) {
        third = third->next;
    }
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = third;

    Node* loopStart = detectLoop(head);
    if (loopStart != NULL) {
        cout << "Loop detected at node " << loopStart->data << endl;
    } else {
        cout << "No loop found" << endl;
    }

    removeLoop(head);

    cout << "List after removing loop: ";
    displayList(head);

    return 0;
}
