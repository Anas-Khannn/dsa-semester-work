#include <iostream>
using namespace std;

/*
    Practice Question 4 (Linked List)

    Rotate a singly linked list to the left by K places.

    Example:
        Input : 1 -> 2 -> 3 -> 4 -> 5 -> 6 , K = 2
        Output: 3 -> 4 -> 5 -> 6 -> 1 -> 2

    Approach:
        1. Find the length and the last node.
        2. K may be larger than the length, so use K % length.
        3. The new head is the (K+1)-th node; the node before it becomes
           the new tail, and the old tail is linked back to the old head.
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

int listLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void rotateLeft(Node*& head, int k) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    int length = listLength(head);
    k = k % length;
    if (k == 0) {
        return;
    }

    // Walk to the new tail (the node just before the new head)
    Node* newTail = head;
    for (int i = 0; i < k - 1; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;

    // Walk to the last node and connect it to the old head
    Node* last = newHead;
    while (last->next != NULL) {
        last = last->next;
    }

    newTail->next = NULL;
    last->next = head;
    head = newHead;
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
    cout << endl;
}

int main() {
    Node* head = NULL;
    for (int i = 1; i <= 6; i++) {
        insertAtEnd(head, i);
    }

    cout << "Before rotation: ";
    displayList(head);

    rotateLeft(head, 2);

    cout << "After rotation : ";
    displayList(head);

    return 0;
}
