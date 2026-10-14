#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    cout << "Name: Anas Khan | Section: B" << endl;

    Node* head = nullptr;

    Node* first  = new Node();
    Node* second = new Node();
    Node* third  = new Node();

    first->data  = 15;
    second->data = 25;
    third->data  = 35;

    first->next  = second;      // 15 -> 25
    second->next = third;       // 25 -> 35
    third->next  = nullptr;     // end of list

    head = first;

    cout << head->data << " -> "
         << head->next->data << " -> "
         << head->next->next->data << endl;

    delete third;
    delete second;
    delete first;
    head = nullptr;
    return 0;
}
