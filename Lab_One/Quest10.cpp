#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "Traffic Light Simulator" << endl;
    cout << "1. Red" << endl;
    cout << "2. Yellow" << endl;
    cout << "3. Green" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Red: Stop!" << endl;
            break;

        case 2:
            cout << "Yellow: Get Ready!" << endl;
            break;

        case 3:
            cout << "Green: Go!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
