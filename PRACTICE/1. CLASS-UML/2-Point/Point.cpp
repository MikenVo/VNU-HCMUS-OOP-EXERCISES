#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

void Point::InputPoint() {
    cout << "Type the x-coordinate of the point: "; cin >> x;
    cout << "Type the y-coordinate of the point: "; cin >> y;
}

void Point::OutputPoint() {
    cout << "The point: (" << x << ";" << y << ")" << endl;
}

double Point::distance(Point other) {
    double result = sqrt(pow((other.x - this->x), 2) + pow((other.y - this->y), 2));
    return result;
}
