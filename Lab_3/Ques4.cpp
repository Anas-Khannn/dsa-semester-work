#include <iostream>
using namespace std;

void showAddress()
{
    // This variable is local to showAddress().
    // Its lifetime begins when the function is called
    // and ends when the function returns.
    int localVariable = 50;

    cout << "Local variable address: "
         << &localVariable << endl;
}

int main()
{
    cout << "First function call:" << endl;
    showAddress();

    cout << "\nSecond function call:" << endl;
    showAddress();

    cout << "\nThird function call:" << endl;
    showAddress();

    return 0;
}