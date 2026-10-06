#include <iostream>
using namespace std;

int main()
{
    int n;
    int arr[50];
    int shifts = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Insertion Sort
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;

            shifts++;
        }

        // Place key in correct position
        arr[j + 1] = key;

        // Print array after each insertion
        cout << "After inserting key " << key << ": ";

        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }

        cout << endl;
    }

    // Print final sorted array
    cout << "\nFinal Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Print total shifts
    cout << "Total Shifts: " << shifts << endl;

    return 0;
}