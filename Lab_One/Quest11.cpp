#include <iostream>
using namespace std;

int main() {
    int marks;
    char grade;

    cout << "Enter your marks: ";
    cin >> marks;

    grade = (marks >= 90) ? 'A' :
            (marks >= 80) ? 'B' :
            (marks >= 70) ? 'C' :
            (marks >= 60) ? 'D' :
            'F';

    cout << "Grade: " << grade << endl;

    return 0;
}
