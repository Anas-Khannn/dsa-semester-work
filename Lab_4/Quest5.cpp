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

    // Optimized Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        // Print array after each pass
        cout << "After Pass " << i + 1 << ": ";

        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << " ";
        }

        cout << endl;

        // Stop early if no swaps occurred
        if (!swapped)
        {
            break;
        }
    }

    cout << "Final Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}