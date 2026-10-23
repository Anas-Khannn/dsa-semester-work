#include <iostream>
using namespace std;

/*
    Practice Question 11 (Linked List)

    Two singly linked lists merge into a Y shape at some node and then
    share the same nodes. Find the intersection node (by address, not value).

    Example:
        List A: 1 -> 2 -> 3
                             \
                              4 -> 5 -> 6
                             /
        List B:        9 -> 8

        Output: Lists intersect at node 4

    Approach:
        1. Count the length of both lists.
        2. Advance the longer list by the difference in lengths.
        3. Move both pointers one step at a time; where they become equal
           is the intersection node.
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

int listLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* findIntersection(Node* headA, Node* headB) {
    int lengthA = listLength(headA);
    int lengthB = listLength(headB);

    Node* longer = (lengthA > lengthB) ? headA : headB;
    Node* shorter = (lengthA > lengthB) ? headB : headA;

    int difference = lengthA - lengthB;
    if (difference < 0) {
        difference = -difference;
    }

    // Align both pointers at the same distance from the end
    for (int i = 0; i < difference; i++) {
        longer = longer->next;
    }

    while (longer != NULL && shorter != NULL) {
        if (longer == shorter) {
            return longer;
        }
        longer = longer->next;
        shorter = shorter->next;
    }

    return NULL;
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
    // Shared tail
    Node* common = NULL;
    insertAtEnd(common, 4);
    insertAtEnd(common, 5);
    insertAtEnd(common, 6);

    Node* listA = NULL;
    insertAtEnd(listA, 1);
    insertAtEnd(listA, 2);
    insertAtEnd(listA, 3);

    Node* listB = NULL;
    insertAtEnd(listB, 9);
    insertAtEnd(listB, 8);

    // Attach both lists to the same shared nodes
    Node* tailA = listA;
    while (tailA->next != NULL) {
        tailA = tailA->next;
    }
    tailA->next = common;

    Node* tailB = listB;
    while (tailB->next != NULL) {
        tailB = tailB->next;
    }
    tailB->next = common;

    cout << "List A: ";
    displayList(listA);
    cout << "List B: ";
    displayList(listB);

    Node* intersection = findIntersection(listA, listB);
    if (intersection != NULL) {
        cout << "Lists intersect at node " << intersection->data << endl;
    } else {
        cout << "Lists do not intersect" << endl;
    }

    return 0;
}
