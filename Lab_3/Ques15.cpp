#include <iostream>
using namespace std;

int main()
{
    int numbers[] = {10, 20, 30, 20, 40, 20, 50};
    int size = 7;

    int target;

    cout << "Enter target value: ";
    cin >> target;

    int lastIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] == target)
        {
            lastIndex = i;
        }
    }

    if (lastIndex != -1)
    {
        cout << "Last occurrence found at index: "
             << lastIndex << endl;
    }
    else
    {
        cout << "Target not found." << endl;
    }

    return 0;
}