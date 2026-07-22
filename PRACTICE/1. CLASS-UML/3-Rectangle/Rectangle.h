#ifndef RECTANGLE
#define RECTANGLE

#include <cmath>

class Point {
    public:
        double x;
        double y;

        void InputPoint();
        void OutputPoint();
        double distance(Point other);
        Point vector(Point end);
};

class Rectangle {
    Point p1;
    Point p2;
    Point p3;
    Point p4;
    
    public:
        bool isRectangle(Point p1, Point p2, Point p3, Point p4);
        double peri(Point p1, Point p2, Point p3, Point p4);
        double area(Point p1, Point p2, Point p3, Point p4);
};

#endif