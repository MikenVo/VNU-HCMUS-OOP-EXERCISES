#include <iostream>
#include <cmath>
#include "Rectangle.h"

using namespace std;

int main() {
    // Initialization
    Point p1, p2, p3, p4;
    Rectangle rec;

    // Input
    p1.InputPoint();
    p2.InputPoint();
    p3.InputPoint();
    p4.InputPoint();

    // If the quadrilateral is not a rectangle, we don't print out the points
    if (rec.isRectangle(p1, p2, p3, p4)) {
        p1.OutputPoint();
        p2.OutputPoint();
        p3.OutputPoint();
        p4.OutputPoint();
    }

    // If the quadrilateral is not a rectangle, perimeter and area are equal to 0
    cout << "Perimeter: " << rec.peri(p1, p2, p3, p4) << endl;
    cout << "Area: " << rec.area(p1, p2, p3, p4) << endl;

    return 0;
}