#include <iostream>
#include <cmath>
using namespace std;

// Function overloading: same function name "AREA",
// different parameter lists

// 1 argument -> Circle (radius)
float AREA(float radius)
{
    return 3.14159f * radius * radius;
}

// 2 arguments -> Rectangle (length, breadth)
float AREA(float length, float breadth)
{
    return length * breadth;
}

// 3 arguments -> Triangle (using Heron's formula)
float AREA(float a, float b, float c)
{
    float s = (a + b + c) / 2.0f;  // semi-perimeter
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    float radius, length, breadth, a, b, c;

    cout << "Enter radius of circle: ";
    cin >> radius;
    cout << "Area of Circle = " << AREA(radius) << endl;

    cout << "\nEnter length and breadth of rectangle: ";
    cin >> length >> breadth;
    cout << "Area of Rectangle = " << AREA(length, breadth) << endl;

    cout << "\nEnter three sides of triangle: ";
    cin >> a >> b >> c;
    cout << "Area of Triangle = " << AREA(a, b, c) << endl;

    return 0;
}