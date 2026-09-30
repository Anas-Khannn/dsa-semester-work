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

    // Create a new array with n + 3 elements
    int newSize = n + 3;
    int* newArr = new int[newSize];

    // Copy original values
    for (int i = 0; i < n; i++)
    {
        newArr[i] = arr[i];
    }

    // Give values to the three new elements
    newArr[n] = 0;
    newArr[n + 1] = 0;
    newArr[n + 2] = 0;

    // Delete old array
    delete[] arr;

    // Make arr point to the new array
    arr = newArr;

    cout << "Expanded array: ";

    for (int i = 0; i < newSize; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    delete[] arr;

    return 0;
}