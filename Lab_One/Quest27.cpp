#include <iostream>
using namespace std;

// Function receives the address of a variable
void doubleValue(int *ptr) {
    *ptr = *ptr * 2;  // Double the value stored at that address
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "Before doubling: " << number << endl;

    // Pass the address of number to the function
    doubleValue(&number);

    cout << "After doubling: " << number << endl;

    return 0;
}
