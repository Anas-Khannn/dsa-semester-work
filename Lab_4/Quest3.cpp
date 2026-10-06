#include <iostream>
using namespace std;

// Iterative Binary Search
int binarySearch(int arr[], int n, int target, int &comparisons)
{
    int low = 0;
    int high = n - 1;

    comparisons = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // Count comparison with arr[mid]
        comparisons++;

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

    // Read number of elements
    cout << "Enter number of elements (maximum 50): ";
    cin >> n;

    // Validate n
    if (n <= 0 || n > 50)
    {
        cout << "Invalid number of elements." << endl;
        return 0;
    }

    // Read sorted array
    cout << "Enter " << n << " integers in ascending order:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Read target
    int target;
    cout << "Enter target value: ";
    cin >> target;

    // Perform binary search
    int comparisons;
    int result = binarySearch(arr, n, target, comparisons);

    // Display result
    if (result != -1)
    {
        cout << "Target found at index: " << result << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}