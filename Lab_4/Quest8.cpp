#include <iostream>
using namespace std;

int main()
{
    int arr[] = {12, 7, 19, 3, 15, 8};
    int n = 6;

    int comparisons = 0;
    int swaps = 0;

    // Selection Sort in descending order
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;

        // Find maximum element
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }

        // Swap maximum with current element
        if (maxIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;

            swaps++;
        }

        // Print array after each pass
        cout << "After Pass " << i + 1 << ": ";

        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << " ";
        }

        cout << endl;
    }

    // Print final array
    cout << "\nFinal Array in Descending Order: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Swaps: " << swaps << endl;

    return 0;
}