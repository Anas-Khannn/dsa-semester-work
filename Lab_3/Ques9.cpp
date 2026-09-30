#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    int* marks = new int[n];

    int passed = 0;
    int failed = 0;

    cout << "Enter the marks:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];

        if (marks[i] >= 50)
        {
            passed++;
        }
        else
        {
            failed++;
        }
    }

    cout << "Marks >= 50: " << passed << endl;
    cout << "Marks < 50: " << failed << endl;

    delete[] marks;

    return 0;
}