#include <iostream>
using namespace std;

int main() {
    int y = 5;

    int a = y++;
    int b = ++y;

    cout << a + b << endl;

    return 0;
}
