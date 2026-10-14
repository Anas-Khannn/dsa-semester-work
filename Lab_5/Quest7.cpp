#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    cout << "Name: Anas Khan | Section: B" << endl;

    Node* head = nullptr;     // empty list

    if (head == nullptr) {
        cout << "List is empty" << endl;
    } else {
        cout << "List is not empty" << endl;
    }
    return 0;
}
