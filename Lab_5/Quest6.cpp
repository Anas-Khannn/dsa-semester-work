#include <iostream>
using namespace std;

int main() {
    cout << "Name: Anas Khan | Section: B" << endl;

    int n;
    cout << "Enter size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Size must be a positive number." << endl;
        return 0;
    }

    int* arr = new int[n];    // allocate at runtime

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double average = (double)sum / n;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;

    delete[] arr;             // release the array
    arr = nullptr;            // avoid dangling pointer
    return 0;
}
