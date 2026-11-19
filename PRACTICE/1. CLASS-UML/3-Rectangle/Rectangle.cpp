#include <iostream>
#include "Rectangle.h"

using namespace std;

// Point methods
void Point::InputPoint() {
    cout << "Type the x-coordinate: "; cin >> x;
    cout << "Type the y-coordinate: "; cin >> y;
}

void Point::OutputPoint() {
    cout << "The point: (" << x << "," << y << ")" << endl;
}

double Point::distance(Point other) {
    double result = sqrt(pow((other.x - this->x), 2) + pow((other.y - this->y), 2));
    return result;
}

Point Point::vector(Point end) {
    Point vec;

    vec.x = end.x - this->x;
    vec.y = end.y - this->y;

    return vec;
}

// Rectangle methods
bool Rectangle::isRectangle(Point p1, Point p2, Point p3, Point p4) {
    double epsilon = 1e-9;

    // Check the distance to ensure there are no coincident points
    if (p1.distance(p2) < epsilon || p1.distance(p4) < epsilon || p2.distance(p3) < epsilon || p3.distance(p4) < epsilon) {
        return false;
    }

    // Use dot product to check if the edges are perpendicular
    if ((abs(p1.vector(p2).x * p1.vector(p4).x + p1.vector(p2).y * p1.vector(p4).y) >= epsilon) ||
        (abs(p2.vector(p1).x * p2.vector(p3).x + p2.vector(p1).y * p2.vector(p3).y) >= epsilon) ||
        (abs(p3.vector(p2).x * p3.vector(p4).x + p3.vector(p2).y * p3.vector(p4).y) >= epsilon) ||
        (abs(p4.vector(p3).x * p4.vector(p1).x + p4.vector(p3).y * p4.vector(p1).y) >= epsilon)) {
        return false;
    }
    else {
        return true;
    }
}

double Rectangle::peri(Point p1, Point p2, Point p3, Point p4) {
    if (!isRectangle(p1, p2, p3, p4)) {
        return 0;
    }

    double result = 2 * (p1.distance(p2) + p2.distance(p3));
    return result;
}

double Rectangle::area(Point p1, Point p2, Point p3, Point p4) {
    if (!isRectangle(p1, p2, p3, p4)) {
        return 0;
    }

    double result = p1.distance(p2) * p2.distance(p3);
    return result;
}