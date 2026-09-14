#include <iostream>
using namespace std;

int main() {

    // ---------------- POINTER ----------------

    int a = 10;             // Create an integer variable a
    int *ptr = &a;          // Pointer stores the address of a

    cout << "Value of a: " << a << endl;

    cout << "Value using pointer: " << *ptr << endl;
    // *ptr accesses the value stored at the address

    *ptr = 20;              // Change a through the pointer

    cout << "New value of a: " << a << endl;


    // ---------------- REFERENCE ----------------

    int b = 30;             // Create another integer variable b
    int &ref = b;            // Reference becomes another name for b

    cout << "Value of b: " << b << endl;

    cout << "Value using reference: " << ref << endl;
    // ref directly refers to b

    ref = 40;               // Change b through the reference

    cout << "New value of b: " << b << endl;

    return 0;
}
