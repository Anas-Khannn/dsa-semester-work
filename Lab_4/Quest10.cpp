#include <iostream>
using namespace std;

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Iterative Binary Search
int binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    int arr[50];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " unsorted integers:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print original array
    cout << "\nOriginal Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Sort using Insertion Sort
    insertionSort(arr, n);

    // Print sorted array
    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Read target
    int target;

    cout << "\nEnter target to search: ";
    cin >> target;

    // Binary Search
    int result = binarySearch(arr, n, target);

    if (result != -1)
    {
        cout << "Target found at index: " << result << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}