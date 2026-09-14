#include <iostream>
using namespace std;

// Area of circle
double area(double radius) {
    return 3.14159 * radius * radius;
}

// Area of rectangle
int area(int length, int width) {
    return length * width;
}

// Area of triangle
double area(double base, double height) {
    return 0.5 * base * height;
}

int main() {
    double radius = 5;
    int length = 10, width = 6;
    double base = 8, height = 4;

    cout << "Area of Circle = " << area(radius) << endl;
    cout << "Area of Rectangle = " << area(length, width) << endl;
    cout << "Area of Triangle = " << area(base, height) << endl;

    return 0;
}
