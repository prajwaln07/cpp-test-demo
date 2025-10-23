#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

class Hexagon {
    double side; // regular hexagon
    Point center;

public:
    Hexagon(double s, Point c) : side(s), center(c) {}

    double perimeter() const {
        return 6 * side;
    }

    double area() const {
        return (3 * sqrt(3) * side * side) / 2.0;
    }

    // Distance from center to any vertex
    double radius() const {
        return side;
    }

    // Check if a point is inside the hexagon (approx using circle radius)
    string pointRelation(const Point& p) const {
        double dx = p.x - center.x;
        double dy = p.y - center.y;
        double dist = sqrt(dx*dx + dy*dy);
        if (dist < radius()) return "Point is inside the hexagon (approx)";
        else if (fabs(dist - radius()) < 1e-9) return "Point is on the hexagon boundary (approx)";
        return "Point is outside the hexagon (approx)";
    }
};

int main() {
    double side;
    Point center, p;

    cin >> side; // hexagon side
    cin >> center.x >> center.y; // hexagon center
    cin >> p.x >> p.y; // point to check

    Hexagon hex(side, center);
    cout << "Hexagon perimeter: " << hex.perimeter() << endl;
    cout << "Hexagon area: " << hex.area() << endl;
    cout << hex.pointRelation(p) << endl;

    return 0;
}
