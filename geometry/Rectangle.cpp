#include <iostream>
#include <cmath>
using namespace std;

class Rectangle {
    double x1, y1, x2, y2;
public:
    Rectangle(double _x1, double _y1, double _x2, double _y2)
        : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

    double area() const {
        return fabs((x2 - x1) * (y2 - y1));
    }

    double perimeter() const {
        return 2 * (fabs(x2 - x1) + fabs(y2 - y1));
    }

    bool contains(double x, double y) const {
        return x >= x1 && x <= x2 && y >= y1 && y <= y2;
    }
};

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle rect(x1, y1, x2, y2);

    cout << "Area: " << rect.area()
         << "\nPerimeter: " << rect.perimeter();

    double px, py;
    cin >> px >> py;
    cout << "\nPoint (" << px << ", " << py << ") "
         << (rect.contains(px, py) ? "is inside rectangle" : "is outside rectangle");
    return 0;
}
