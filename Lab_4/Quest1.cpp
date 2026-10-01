#include <iostream>
#include <string>
using namespace std;

int main() {
    const int SIZE = 10;

    string names[SIZE];

    names[0] = "Anas Khan";
    names[1] = "Hilal";
    for (int i = 2; i < SIZE; i++) {
        names[i] = "";
    }

    cout << "Student 1: " << names[0] << endl;
    cout << "Student 2: " << names[1] << endl;

    cout << "\nSize of the array: " << SIZE << endl;
    cout << "Size in bytes: " << sizeof(names) << endl;

    cout << "\nAll " << SIZE << " elements of the array:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "names[" << i << "] = " << names[i] << endl;
    }

    return 0;
}
