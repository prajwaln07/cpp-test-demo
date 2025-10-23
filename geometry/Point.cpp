#include <iostream>
using namespace std;

struct Point {
    double x, y;
};

bool getLineIntersection(Point p1, Point p2, Point p3, Point p4, Point &intersection) {
    double a1 = p2.y - p1.y;
    double b1 = p1.x - p2.x;
    double c1 = a1 * p1.x + b1 * p1.y;

    double a2 = p4.y - p3.y;
    double b2 = p3.x - p4.x;
    double c2 = a2 * p3.x + b2 * p3.y;

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        return false; // Lines are parallel
    } else {
        intersection.x = (b2 * c1 - b1 * c2) / determinant;
        intersection.y = (a1 * c2 - a2 * c1) / determinant;
        return true;
    }
}

int main() {
    Point p1 = {1, 1}, p2 = {4, 4};
    Point p3 = {1, 8}, p4 = {2, 4};
    Point intersection;

    if (getLineIntersection(p1, p2, p3, p4, intersection)) {
        cout << "Intersection point: (" << intersection.x << ", " << intersection.y << ")" << endl;
    } else {
        cout << "Lines are parallel, no intersection." << endl;
    }

    return 0;
}
