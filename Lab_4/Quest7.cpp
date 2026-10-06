#include <iostream>
using namespace std;

int main()
{
    int n;
    int arr[50];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Selection Sort
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // Find minimum element
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Print selected minimum before swap
        cout << "Pass " << i + 1 << ": ";
        cout << "Minimum = " << arr[minIndex];
        cout << ", Index = " << minIndex << endl;

        // Swap minimum with current element
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        // Print array after each pass
        cout << "Array after Pass " << i + 1 << ": ";

        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << " ";
        }

        cout << endl;
    }

    // Final sorted array
    cout << "\nFinal Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}