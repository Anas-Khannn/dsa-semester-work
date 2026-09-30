#include <iostream>
using namespace std;

int main()
{
    // Allocate an array of 5 integers dynamically.
    int* numbers = new int[5];

    for (int i = 0; i < 5; i++)
    {
        numbers[i] = i + 1;
    }

    cout << "Dynamic array values:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    /*
        Intentionally commented out for demonstration:

        delete[] numbers;

        Without delete[], the dynamically allocated memory
        is not released while the program is running.
    */

    return 0;
}