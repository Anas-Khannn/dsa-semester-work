#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    int rollNo;
    float marks;
};

int main() {
    cout << "Name: Anas Khan | Section: B" << endl;

    Student s1;

    cout << "Enter name: ";
    getline(cin, s1.name);
    cout << "Enter age: ";
    cin >> s1.age;
    cout << "Enter roll number: ";
    cin >> s1.rollNo;
    cout << "Enter marks: ";
    cin >> s1.marks;

    cout << "\n----- Student Record -----" << endl;
    cout << "Name    : " << s1.name << endl;
    cout << "Age     : " << s1.age << endl;
    cout << "Roll No : " << s1.rollNo << endl;
    cout << "Marks   : " << s1.marks << endl;
    return 0;
}
