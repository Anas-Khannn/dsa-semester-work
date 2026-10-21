#include <iostream>
using namespace std;

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

void insertAtStart(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
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

void insertAtAny(Node*& head, int value, int position) {
    if (head == NULL) {
        insertAtStart(head, value);
        return;
    }
    
    // Insert before the first node whose data equals position
    if (head->data == position) {
        insertAtStart(head, value);
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != position) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        // If position not found, insert at end
        insertAtEnd(head, value);
        return;
    }
    
    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    
    // Practice sequence
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtStart(head, 5);
    insertAtAny(head, 15, 20);  // insert before first node with data 20
    insertAtStart(head, 2);
    insertAtAny(head, 12, 15);  // insert before first node with data 15
    
    displayList(head);
    
    return 0;
}
