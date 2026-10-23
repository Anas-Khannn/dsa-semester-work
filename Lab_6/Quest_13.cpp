#include <iostream>
using namespace std;

/*
    Practice Question 13 (Linked List)

    Sort a singly linked list using Merge Sort (in-place by rearranging links).

    Example:
        Input : 4 -> 2 -> 1 -> 3
        Output: 1 -> 2 -> 3 -> 4

    Approach:
        1. Split the list into two halves using slow and fast pointers.
        2. Recursively sort each half with merge sort.
        3. Merge the two sorted halves back together.
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

Node* mergeLists(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Node* result = NULL;
    if (left->data <= right->data) {
        result = left;
        result->next = mergeLists(left->next, right);
    } else {
        result = right;
        result->next = mergeLists(right->next, left);
    }
    return result;
}

void splitList(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node* a = NULL;
    Node* b = NULL;
    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = mergeLists(a, b);
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
    int values[] = {4, 2, 1, 3, 5};
    for (int i = 0; i < 5; i++) {
        insertAtEnd(head, values[i]);
    }

    cout << "Before sorting: ";
    displayList(head);

    mergeSort(&head);

    cout << "After sorting : ";
    displayList(head);

    return 0;
}
