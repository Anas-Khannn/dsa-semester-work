#include <iostream>
using namespace std;

/*
    Practice Question (Linked List)

    Fold a singly linked list in half so that the nodes alternate
    between the start and the end of the list.

    Example:
        Input : 1 -> 2 -> 3 -> 4 -> 5
        Output: 1 -> 5 -> 2 -> 4 -> 3

        Input : 1 -> 2 -> 3 -> 4
        Output: 1 -> 4 -> 2 -> 3

    Approach:
        1. Find the middle of the list using slow and fast pointers.
        2. Reverse the second half.
        3. Merge the two halves by taking one node from each.
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

void foldList(Node*& head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    // Slow moves one step, fast moves two steps, so slow ends at the middle
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list and reverse the second half
    Node* secondHalf = slow->next;
    slow->next = NULL;
    secondHalf = reverseList(secondHalf);

    // Weave the two halves together: first, last, second, second-last, ...
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
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    cout << "Before folding: ";
    displayList(head);

    foldList(head);

    cout << "After folding : ";
    displayList(head);

    return 0;
}
