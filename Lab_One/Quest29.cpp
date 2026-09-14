#include <iostream>
using namespace std;

int main() {
    int rows, columns;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    // Create an array of pointers
    int **matrix = new int*[rows];

    // Create an integer array for each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }

    // Fill the matrix
    cout << "Enter elements of the matrix:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> matrix[i][j];
        }
    }

    // Display the matrix
    cout << "Matrix:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Free each row
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    // Free the array of row pointers
    delete[] matrix;

    return 0;
}
