#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float totalMarks;
};

int main() {
    Student s[2];

    for (int i = 0; i < 2; i++) {
        cout << "Enter data for student " << i + 1 << endl;
        cout << "Name: ";
        getline(cin, s[i].name);
        cout << "Age: ";
        cin >> s[i].age;
        cout << "Total Marks: ";
        cin >> s[i].totalMarks;
        cin.ignore();
    }

    cout << "\nStudent Information" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Age: " << s[i].age << endl;
        cout << "Total Marks: " << s[i].totalMarks << endl;
        cout << endl;
    }

    float average = (s[0].totalMarks + s[1].totalMarks) / 2;
    cout << "Average of Total Marks: " << average << endl;

    return 0;
}
