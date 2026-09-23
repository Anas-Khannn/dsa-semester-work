#include <iostream>
using namespace std;

void display(const int* a, int size) {
    for (int i = 0; i < size; ++i)
        cout << a[i] << " ";
    cout << '\n';
}

int sum(const int* a, int size) {
    int total = 0;
    for (int i = 0; i < size; ++i)
        total += a[i];
    return total;
}

int minValue(const int* a, int size) {
    if (size <= 0) return 0;
    int mn = a[0];
    for (int i = 1; i < size; ++i)
        if (a[i] < mn) mn = a[i];
    return mn;
}

int maxValue(const int* a, int size) {
    if (size <= 0) return 0;
    int mx = a[0];
    for (int i = 1; i < size; ++i)
        if (a[i] > mx) mx = a[i];
    return mx;
}

int countEven(const int* a, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (a[i] % 2 == 0) ++count;
    return count;
}
int main() {
 int a[] = {10, 20, 15, 30, 41, 50};
 int size = 6; 
cout << "Array: "; 
display(a, size); 
cout << "Sum: " << sum(a, size) << endl; cout << "Minimum: " << minValue(a, size) << endl; 
cout << "Maximum: " << maxValue(a, size) << endl; cout << "Even numbers: " << countEven(a, size) << endl; return 0; 
}
