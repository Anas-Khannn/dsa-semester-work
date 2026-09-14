#include <iostream>
using namespace std;

// Our own strlen() function
int myStrlen(char str[]) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

// Our own strrev() function
void myStrrev(char str[]) {
    int start = 0;
    int end = myStrlen(str) - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char str[100];

    cout << "Enter a string: ";
    cin.getline(str, 100);

    cout << "Length: " << myStrlen(str) << endl;

    myStrrev(str);

    cout << "Reversed string: " << str << endl;

    return 0;
}
