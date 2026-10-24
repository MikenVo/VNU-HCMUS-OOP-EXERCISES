#ifndef POINT_H
#define POINT_H

#include <cmath>

class Point {
    double x;
    double y;

    public:
        void InputPoint();
        void OutputPoint();
        double distance(Point other);
};

#endif