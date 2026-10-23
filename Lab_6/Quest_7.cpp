#include <iostream>
using namespace std;

/*
    Practice Question 7 (Linked List)

    Check whether a singly linked list is a palindrome
    (reads the same forwards and backwards) in O(n) time.

    Example:
        Input : 1 -> 2 -> 3 -> 2 -> 1
        Output: Palindrome

        Input : 1 -> 2 -> 3 -> 4
        Output: Not a palindrome

    Approach:
        1. Find the middle using slow and fast pointers.
        2. Reverse the second half of the list.
        3. Compare the first half and the reversed second half node by node.
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
    while (head != NULL) {
        Node* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // Find the middle
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half (slow->next onwards)
    Node* secondHalf = reverseList(slow->next);

    // Compare the two halves
    Node* firstHalf = head;
    Node* temp = secondHalf;
    bool palindrome = true;
    while (temp != NULL) {
        if (firstHalf->data != temp->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    // Restore the list to its original shape
    slow->next = reverseList(secondHalf);
    return palindrome;
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
    int valuesA[] = {1, 2, 3, 2, 1};
    for (int i = 0; i < 5; i++) {
        insertAtEnd(listA, valuesA[i]);
    }

    Node* listB = NULL;
    int valuesB[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        insertAtEnd(listB, valuesB[i]);
    }

    cout << "List A      : ";
    displayList(listA);
    cout << "List B      : ";
    displayList(listB);

    cout << "List A is " << (isPalindrome(listA) ? "a palindrome" : "not a palindrome") << endl;
    cout << "List B is " << (isPalindrome(listB) ? "a palindrome" : "not a palindrome") << endl;

    return 0;
}
