#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " integers:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;

    cout << "Enter value to search: ";
    cin >> target;

    int index = -1;

    // Linear search
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        cout << "Target found at index: " << index << endl;
    }
    else
    {
        cout << "Target not found." << endl;
    }

    delete[] arr;

    return 0;
}