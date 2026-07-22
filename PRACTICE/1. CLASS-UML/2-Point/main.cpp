#include <iostream>
#include "Point.h"
using namespace std;

int main() {
    Point point1;
    Point point2;
    double result;

    point1.InputPoint();
    point2.InputPoint();
    
    point1.OutputPoint();
    point2.OutputPoint();

    result = point1.distance(point2);
    cout << "The distance between two points is " << result << endl;

    return 0;
}