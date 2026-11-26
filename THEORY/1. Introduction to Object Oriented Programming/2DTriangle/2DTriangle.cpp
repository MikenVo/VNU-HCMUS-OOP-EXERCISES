// Using the data structure struct, implement the following structures and functions:
// - struct Point: data structure for a 2-D point.
// - struct Triangle: contains the information of the 3 vertices 
// - A function to calculate a distance between 2 points
// - Functions to calculate the perimeter and area of a triangle

#include <iostream>
#include <cmath>
using namespace std;

// Structures
struct Point {
	double x;
	double y;
};

struct Triangle {
	Point p1;
	Point p2;
	Point p3;
};

// Calculate the distance of two points
double TwoPointsDistance(Point p1, Point p2) {
	double answer = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
	return answer;
}

// Calculate the perimeter
double perimeter(Triangle triangle) {
	// Calculate the lengths of the edges
	double l1 = TwoPointsDistance(triangle.p1, triangle.p2);
	double l2 = TwoPointsDistance(triangle.p2, triangle.p3);
	double l3 = TwoPointsDistance(triangle.p1, triangle.p3);

	return l1 + l2 + l3;
}

// Calculate the area
double area(Triangle triangle) {
	// Use Heron's Formula
	// Calculate the half perimeter
	double half_perimeter = perimeter(triangle) / 2.0;

	// Calculate the lengths of the edges
	double l1 = TwoPointsDistance(triangle.p1, triangle.p2);
	double l2 = TwoPointsDistance(triangle.p2, triangle.p3);
	double l3 = TwoPointsDistance(triangle.p1, triangle.p3);

	double answer = sqrt(half_perimeter * (half_perimeter - l1) * (half_perimeter - l2) * (half_perimeter - l3));

	return answer;
}

int main() {
	Triangle triangle;
	cout << "Please input the points of the triangle: " << endl;
	cout << "Point 1: "; cin >> triangle.p1.x >> triangle.p2.y;
	cout << "Point 2: "; cin >> triangle.p2.x >> triangle.p2.y;
	cout << "Point 3: "; cin >> triangle.p3.x >> triangle.p3.y;

	cout << "Edge p1p2: "; cout << TwoPointsDistance(triangle.p1, triangle.p2) << endl;
	cout << "Edge p1p3: "; cout << TwoPointsDistance(triangle.p1, triangle.p3) << endl;
	cout << "Edge p2p3: "; cout << TwoPointsDistance(triangle.p2, triangle.p3) << endl;

	cout << "Perimeter: "; cout << perimeter(triangle) << endl;
	cout << "Area: "; cout << area(triangle);

	return 0;
}