#include <iostream>
using namespace std;

void binarySearchTrace(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    cout << "\nSearching for: " << target << endl;
    cout << "---------------------------------------------\n";
    cout << "Low\tHigh\tMid\tarr[mid]\tDecision\n";

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            cout << low << "\t"
                 << high << "\t"
                 << mid << "\t"
                 << arr[mid] << "\t\tFound\n";

            cout << "Target " << target
                 << " found at index " << mid << ".\n";

            return;
        }
        else if (arr[mid] < target)
        {
            cout << low << "\t"
                 << high << "\t"
                 << mid << "\t"
                 << arr[mid] << "\t\tRight\n";

            low = mid + 1;
        }
        else
        {
            cout << low << "\t"
                 << high << "\t"
                 << mid << "\t"
                 << arr[mid] << "\t\tLeft\n";

            high = mid - 1;
        }
    }

    cout << "Target " << target
         << " not found. Search stops because low > high.\n";
}

int main()
{
    int arr[] = {4, 9, 15, 22, 31, 47, 58, 63, 71};
    int size = 9;

    // Search for 47
    binarySearchTrace(arr, size, 47);

    // Search for 20
    binarySearchTrace(arr, size, 20);

    return 0;
}