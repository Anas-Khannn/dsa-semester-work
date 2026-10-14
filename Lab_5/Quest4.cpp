#include <iostream>
using namespace std;

int main() {
    cout << "Name: Anas Khan | Section: B" << endl;

    int value;
    cout << "Enter an integer: ";
    cin >> value;

    int* p = &value;          // p stores the address of value

    cout << "Value before modification: " << value << endl;

    *p = *p + 10;             // modify using only the pointer

    cout << "Value after modification: " << value << endl;
    return 0;
}
