#include <iostream>
using namespace std;

/*
    Practice Question 8 (Linked List)

    Remove all duplicate nodes from an UNSORTED singly linked list,
    keeping only the first occurrence of every value.

    Example:
        Input : 3 -> 1 -> 3 -> 2 -> 1 -> 4 -> 2
        Output: 3 -> 1 -> 2 -> 4

    Approach:
        For every node, scan the rest of the list with a second pointer
        and delete any node that holds the same value.
        (A sorted list can be cleaned in one pass, but this list is unsorted.)
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

void removeDuplicates(Node* head) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        Node* runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                Node* duplicate = runner->next;
                runner->next = duplicate->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
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
    int values[] = {3, 1, 3, 2, 1, 4, 2};
    for (int i = 0; i < 7; i++) {
        insertAtEnd(head, values[i]);
    }

    cout << "Before removing duplicates: ";
    displayList(head);

    removeDuplicates(head);

    cout << "After removing duplicates : ";
    displayList(head);

    return 0;
}
