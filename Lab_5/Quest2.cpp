#include <iostream>
#include <string>
using namespace std;

struct Node {
    string StudentName;
    string Registration;
    float totalMarks;
    Node* next;
};

int main() {
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;
    Node* fifth = new Node;
    Node* sixth = new Node;
    Node* seventh = new Node;
    Node* eighth = new Node;
    Node* ninth = new Node;
    Node* tenth = new Node;

    head->StudentName = "Ali Raza";
    head->Registration = "25PWCS101";
    head->totalMarks = 78.5;

    second->StudentName = "Sara Ahmed";
    second->Registration = "25PWCS102";
    second->totalMarks = 88.0;

    third->StudentName = "Anas Khan";
    third->Registration = "25PWCS1691";
    third->totalMarks = 92.5;

    fourth->StudentName = "Hassan Malik";
    fourth->Registration = "25PWCS104";
    fourth->totalMarks = 71.5;

    fifth->StudentName = "Zainab Noor";
    fifth->Registration = "25PWCS105";
    fifth->totalMarks = 84.0;

    sixth->StudentName = "Usman Tariq";
    sixth->Registration = "25PWCS106";
    sixth->totalMarks = 66.5;

    seventh->StudentName = "Fatima Zahra";
    seventh->Registration = "25PWCS107";
    seventh->totalMarks = 95.0;

    eighth->StudentName = "Bilal Hussain";
    eighth->Registration = "25PWCS108";
    eighth->totalMarks = 73.0;

    ninth->StudentName = "Ayesha Siddiq";
    ninth->Registration = "25PWCS109";
    ninth->totalMarks = 81.5;

    tenth->StudentName = "Omar Farooq";
    tenth->Registration = "25PWCS110";
    tenth->totalMarks = 89.0;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    tenth->next = nullptr;

    cout << "Linked List of 10 Students" << endl;
    Node* current = head;
    int count = 1;
    while (current != nullptr) {
        cout << "Node " << count << endl;
        cout << "Name: " << current->StudentName << endl;
        cout << "Registration: " << current->Registration << endl;
        cout << "Total Marks: " << current->totalMarks << endl;
        cout << "Next: " << current->next << endl << endl;
        current = current->next;
        count++;
    }

    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
