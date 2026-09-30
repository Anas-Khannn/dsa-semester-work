#include <iostream>
using namespace std;

// Creates and returns a dynamic array
int* createArray(int n)
{
    int* p = new int[n];

    return p;
}

// Deletes the array and sets the pointer to nullptr
void destroyArray(int*& p)
{
    delete[] p;
    p = nullptr;
}

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = createArray(n);

    cout << "Enter " << n << " integers:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    destroyArray(arr);

    if (arr == nullptr)
    {
        cout << "Array destroyed successfully." << endl;
    }

    return 0;
}