#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];

    cout << "Enter the 9 values for a 3x3 matrix (row by row):\n";
    for (int i = 0; i < 3; i++) {
        cout << "Row " << (i + 1) << ": ";
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nThe 3x3 matrix is:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}