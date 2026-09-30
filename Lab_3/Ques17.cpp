#include <iostream>
using namespace std;

int main()
{
    int numbers[] = {15, 25, 35, 45, 55, 65, 75};
    int size = 7;

    int target;

    cout << "Enter target value: ";
    cin >> target;

    int index = -1;
    int comparisons = 0;

    for (int i = 0; i < size; i++)
    {
        comparisons++;

        if (numbers[i] == target)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        cout << "Target found at index: " << index << endl;
        cout << "Comparisons performed: "
             << comparisons << endl;
    }
    else
    {
        cout << "Target not found." << endl;
        cout << "Comparisons performed: "
             << comparisons << endl;
    }

    return 0;
}