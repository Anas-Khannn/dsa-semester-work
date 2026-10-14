#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    cout << "Name: Anas Khan | Section: B" << endl;

    // Build the four-node list
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};

    // Single traversal: display, count, and sum
    Node* temp = head;
    int count = 0, sum = 0;

    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        count++;
        sum += temp->data;
        temp = temp->next;
    }
    cout << endl;

    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    // Release all nodes safely
    temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = nullptr;
    return 0;
}
