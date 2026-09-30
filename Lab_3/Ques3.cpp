#include <iostream>
using namespace std;

int main()
{
    // Fixed (static) array
    // The array has a fixed size of 5.
    // Its memory is automatically managed.
    int fixedArray[5] = {10, 20, 30, 40, 50};

    // Dynamic array
    // Memory is allocated at runtime using new.
    // It must be released using delete[].
    int* dynamicArray = new int[5];

    for (int i = 0; i < 5; i++)
    {
        dynamicArray[i] = (i + 1) * 10;
    }

    cout << "Addresses of fixed array elements:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "fixedArray[" << i << "] = "
             << &fixedArray[i] << endl;
    }

    cout << "\nAddresses of dynamic array elements:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "dynamicArray[" << i << "] = "
             << &dynamicArray[i] << endl;
    }

    // Release dynamically allocated memory.
    delete[] dynamicArray;

    return 0;
}