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

    int maximum = arr[0];
    int minimum = arr[0];

    // Find maximum and minimum without STL algorithms
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }

        if (arr[i] < minimum)
        {
            minimum = arr[i];
        }
    }

    cout << "Maximum = " << maximum << endl;
    cout << "Minimum = " << minimum << endl;

    delete[] arr;

    return 0;
}