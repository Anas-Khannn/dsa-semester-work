#include <iostream>
using namespace std;

/*
    Practice Question 14 (Linked List)

    Given a sorted singly linked list, insert a new node
    with a given value so that the list remains sorted in ascending order.

    Example:
        Input : 1 -> 2 -> 4 -> 5 , value = 3
        Output: 1 -> 2 -> 3 -> 4 -> 5

        Input : 1 -> 2 -> 3 -> 4 , value = 5
        Output: 1 -> 2 -> 3 -> 4 -> 5

    Approach:
        1. If the list is empty or the new value is <= head data, insert at start.
        2. Traverse to find the node after which the new node should go.
        3. Insert in place by adjusting links.
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

void insertInSortedList(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
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
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    cout << "Before insertion: ";
    displayList(head);

    int value = 3;
    insertInSortedList(head, value);
    cout << "Inserted " << value << endl;

    cout << "After insertion : ";
    displayList(head);

    return 0;
}
