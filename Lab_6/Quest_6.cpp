#include <iostream>
using namespace std;

/*
    Practice Question 6 (Linked List)

    Merge two sorted singly linked lists into one sorted list
    without creating any new nodes (reuse the existing nodes).

    Example:
        List A: 1 -> 4 -> 7
        List B: 2 -> 3 -> 8 -> 9
        Output: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9

    Approach:
        1. Use a dummy node to build the result list.
        2. Compare the front nodes of both lists and attach the smaller one.
        3. When one list runs out, attach whatever is left of the other.
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

Node* mergeSorted(Node* a, Node* b) {
    Node* dummy = createNode(0);
    Node* tail = dummy;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    // Attach the remaining part of whichever list is left
    if (a != NULL) {
        tail->next = a;
    } else {
        tail->next = b;
    }

    Node* result = dummy->next;
    delete dummy;
    return result;
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
    Node* listA = NULL;
    insertAtEnd(listA, 1);
    insertAtEnd(listA, 4);
    insertAtEnd(listA, 7);

    Node* listB = NULL;
    insertAtEnd(listB, 2);
    insertAtEnd(listB, 3);
    insertAtEnd(listB, 8);
    insertAtEnd(listB, 9);

    cout << "List A : ";
    displayList(listA);
    cout << "List B : ";
    displayList(listB);

    Node* merged = mergeSorted(listA, listB);

    cout << "Merged : ";
    displayList(merged);

    return 0;
}
