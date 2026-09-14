#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int search, position = -1;

    cout << "Enter number to search: ";
    cin >> search;

    for (int i = 0; i < 5; i++) {
        if (arr[i] == search) {
            position = i;
            break;
        }
    }

    if (position != -1) {
        cout << "Number found at index: " << position << endl;
    } else {
        cout << "Number not found." << endl;
    }

    return 0;
}
