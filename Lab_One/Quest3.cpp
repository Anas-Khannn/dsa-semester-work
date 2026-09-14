#include <iostream>
using namespace std;

int main() {
    float subject1, subject2, subject3;
    float total, average;

    cout << "Enter marks for Subject 1: ";
    cin >> subject1;

    cout << "Enter marks for Subject 2: ";
    cin >> subject2;

    cout << "Enter marks for Subject 3: ";
    cin >> subject3;

    total = subject1 + subject2 + subject3;
    average = total / 3;

    cout << "Total Marks: " << total << endl;
    cout << "Average Marks: " << average << endl;

    return 0;
}
