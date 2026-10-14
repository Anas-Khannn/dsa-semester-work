#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    cout << "Name: Anas Khan | Section: B" << endl;

    Node* head = nullptr;

    Node* first = new Node();   // create node dynamically
    first->data = 50;
    first->next = nullptr;

    head = first;               // head points to the first node

    cout << "First node data = " << head->data << endl;

    delete first;               // free the node
    first = nullptr;
    head = nullptr;
    return 0;
}
