#include <iostream>
using namespace std;

int main()
{
    int marks[] = {75, 60, 50, 75, 90, 75, 40, 60};
    int size = 8;

    int target;

    cout << "Enter target mark: ";
    cin >> target;

    int count = 0;

    cout << "Target found at indices: ";

    for (int i = 0; i < size; i++)
    {
        if (marks[i] == target)
        {
            cout << i << " ";
            count++;
        }
    }

    if (count == 0)
    {
        cout << "None";
    }

    cout << endl;

    cout << "Total occurrences: " << count << endl;

    return 0;
}