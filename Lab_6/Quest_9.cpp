#include <iostream>
using namespace std;

/*
    Practice Question 9 (Linked List)

    Swap every two adjacent nodes of a singly linked list.

    Example:
        Input : 1 -> 2 -> 3 -> 4 -> 5
        Output: 2 -> 1 -> 4 -> 3 -> 5

    Note:
        Change the links only, not just the values, and if the list has
        an odd number of nodes the last node stays in place.

    Approach:
        Use a dummy node before the head. For each pair:
            first = prev->next
            second = first->next
            prev->next = second
            first->next = second->next
            second->next = first
            prev = first
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

void swapPairs(Node*& head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node* dummy = createNode(0);
    dummy->next = head;
    Node* prev = dummy;

    while (prev->next != NULL && prev->next->next != NULL) {
        Node* first = prev->next;
        Node* second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    head = dummy->next;
    delete dummy;
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

    cout << "Before swapping: ";
    displayList(head);

    swapPairs(head);

    cout << "After swapping : ";
    displayList(head);

    return 0;
}
