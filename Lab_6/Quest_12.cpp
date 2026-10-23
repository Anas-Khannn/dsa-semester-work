#include <iostream>
using namespace std;

/*
    Practice Question 12 (Linked List)

    Reorder a singly linked list in the following pattern:
    L0 -> L1 -> L2 -> ... -> Ln-1 -> Ln
    becomes
    L0 -> Ln -> L1 -> L(n-1) -> L2 -> L(n-2) -> ...

    Example:
        Input : 1 -> 2 -> 3 -> 4 -> 5
        Output: 1 -> 5 -> 2 -> 4 -> 3

        Input : 1 -> 2 -> 3 -> 4
        Output: 1 -> 4 -> 2 -> 3

    Approach:
        1. Find the middle of the list.
        2. Reverse the second half.
        3. Merge the first half and reversed second half by taking
           one node from the first and one from the second alternately.
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

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

void reorderList(Node*& head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    // Find middle
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = slow->next;
    slow->next = NULL;

    // Reverse second half
    secondHalf = reverseList(secondHalf);

    // Merge first half and reversed second half
    Node* firstHalf = head;
    while (secondHalf != NULL) {
        Node* firstNext = firstHalf->next;
        Node* secondNext = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = firstNext;

        firstHalf = firstNext;
        secondHalf = secondNext;
    }
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
    for (int i = 1; i <= 5; i++) {
        insertAtEnd(head, i);
    }

    cout << "Before reorder: ";
    displayList(head);

    reorderList(head);

    cout << "After reorder : ";
    displayList(head);

    return 0;
}
