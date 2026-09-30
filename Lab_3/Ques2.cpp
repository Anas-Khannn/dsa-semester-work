// Anas Khan 
// Registration Number: 25pwcs1691
// Section: B
#include <iostream>
using namespace std;

// Global variable
// Scope: The entire program/file after its declaration.
// Lifetime: Exists from program start until the program ends.
int globalNumber = 100;

void task1()
{
    // Local variables
    // Scope: Only inside this function.
    // Lifetime: Created when the function is called and destroyed
    // when the function finishes.
    int localNumber1 = 200;
    int localNumber2 = 300;

    cout << "Global variable:" << endl;
    cout << "Value: " << globalNumber << endl;
    cout << "Address: " << &globalNumber << endl;

    cout << "\nLocal variable 1:" << endl;
    cout << "Value: " << localNumber1 << endl;
    cout << "Address: " << &localNumber1 << endl;

    cout << "\nLocal variable 2:" << endl;
    cout << "Value: " << localNumber2 << endl;
    cout << "Address: " << &localNumber2 << endl;
}

int main()
{
    task1();

    return 0;
}