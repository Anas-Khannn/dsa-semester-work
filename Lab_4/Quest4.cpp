#include <iostream>
using namespace std;

// Recursive Binary Search
int recursiveBinarySearch(int arr[], int low, int high, int target)
{
    // Base case: target not found
    if (low > high)
    {
        return -1;
    }

    // Calculate middle index
    int mid = (low + high) / 2;

    // Print the mid index examined
    cout << "Checking mid index: " << mid
         << " (value = " << arr[mid] << ")" << endl;

    // Target found
    if (arr[mid] == target)
    {
        return mid;
    }

    // Search left half
    if (target < arr[mid])
    {
        return recursiveBinarySearch(arr, low, mid - 1, target);
    }

    // Search right half
    return recursiveBinarySearch(arr, mid + 1, high, target);
}

int main()
{
    int arr[] = {4, 9, 15, 22, 31, 47, 58, 63, 71};
    int n = 9;

    // Test 1: Target is present
    int target1 = 47;

    cout << "Searching for: " << target1 << endl;

    int result1 = recursiveBinarySearch(arr, 0, n - 1, target1);

    if (result1 != -1)
    {
        cout << "Target found at index: " << result1 << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    cout << endl;

    // Test 2: Target is absent
    int target2 = 20;

    cout << "Searching for: " << target2 << endl;

    int result2 = recursiveBinarySearch(arr, 0, n - 1, target2);

    if (result2 != -1)
    {
        cout << "Target found at index: " << result2 << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}