#include <iostream>
using namespace std;

int main()
{
    int rollNumbers[] = {105, 102, 108, 101, 110, 103};
    int size = 6;

    int target;

    cout << "Enter student roll number to search: ";
    cin >> target;

    int index = -1;

    // Sequential search
    for (int i = 0; i < size; i++)
    {
        if (rollNumbers[i] == target)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        cout << "Roll number found at index: " << index << endl;
    }
    else
    {
        cout << "Roll number not found." << endl;
    }

    return 0;
}