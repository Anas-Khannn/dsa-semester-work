#include <iostream>
using namespace std;

/*
    Practice Question 15 (Linked List)

    Given two singly linked lists, reverse each list individually
    and then add them as if they were numbers (digit by digit),
    returning the sum as a linked list in the same order as numbers
    (most significant digit first).

    Example:
        List A: 1 -> 2 -> 3        (represents 123)
        List B: 4 -> 5            (represents 45)
        Result: 1 -> 6 -> 8        (123 + 45 = 168)

    Approach:
        1. Reverse both lists to start from least significant digit.
        2. Add node by node with carry.
        3. Reverse the result to get most significant digit first.
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

Node* addLists(Node* listA, Node* listB) {
    Node* revA = reverseList(listA);
    Node* revB = reverseList(listB);

    Node* dummy = createNode(0);
    Node* tail = dummy;
    int carry = 0;

    while (revA != NULL || revB != NULL || carry != 0) {
        int sum = carry;
        if (revA != NULL) {
            sum += revA->data;
            revA = revA->next;
        }
        if (revB != NULL) {
            sum += revB->data;
            revB = revB->next;
        }

        carry = sum / 10;
        tail->next = createNode(sum % 10);
        tail = tail->next;
    }

    Node* resultRev = dummy->next;
    delete dummy;
    Node* result = reverseList(resultRev);
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
    Node* listB = NULL;

    // List A: 1 -> 2 -> 3  (123)
    insertAtEnd(listA, 1);
    insertAtEnd(listA, 2);
    insertAtEnd(listA, 3);

    // List B: 4 -> 5        (45)
    insertAtEnd(listB, 4);
    insertAtEnd(listB, 5);

    cout << "List A : ";
    displayList(listA);
    cout << "List B : ";
    displayList(listB);

    Node* result = addLists(listA, listB);

    cout << "Sum    : ";
    displayList(result);

    return 0;
}
