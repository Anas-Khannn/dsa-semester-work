#include <iostream>
using namespace std;

/*
    Practice Question 10 (Linked List)

    Delete the N-th node from the END of a singly linked list
    using only ONE traversal of the list.

    Example:
        Input : 1 -> 2 -> 3 -> 4 -> 5 , N = 2
        Output: 1 -> 2 -> 3 -> 5        (the 4th node was deleted)

    Approach:
        Use two pointers with a gap of N nodes.
        1. Put "first" N+1 steps ahead of "second" (starting both at a dummy node).
        2. Move both until "first" reaches NULL.
        3. "second" is now just before the node to delete, so unlink it.
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

bool deleteNthFromEnd(Node*& head, int n) {
    if (head == NULL || n <= 0) {
        return false;
    }

    Node* dummy = createNode(0);
    dummy->next = head;
    Node* first = dummy;
    Node* second = dummy;

    // Create a gap of n nodes
    for (int i = 0; i <= n; i++) {
        if (first == NULL) {
            delete dummy;
            return false;   // n is greater than the length
        }
        first = first->next;
    }

    // Move both pointers until first falls off the end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    Node* target = second->next;
    second->next = target->next;
    delete target;

    head = dummy->next;
    delete dummy;
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
    cout << endl;
}

int main() {
    Node* head = NULL;
    for (int i = 1; i <= 5; i++) {
        insertAtEnd(head, i);
    }

    cout << "Before deletion: ";
    displayList(head);

    int n = 2;
    if (deleteNthFromEnd(head, n)) {
        cout << "Deleted node " << n << " from the end" << endl;
    } else {
        cout << "Invalid N" << endl;
    }

    cout << "After deletion : ";
    displayList(head);

    return 0;
}
