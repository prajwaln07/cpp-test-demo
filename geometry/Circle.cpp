#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) {
        if (r <= 0)
            throw invalid_argument("Radius must be positive");
        radius = r;
    }

    void setRadius(double r) {
        if (r <= 0)
            throw invalid_argument("Radius must be positive");
        radius = r;
    }

    double getRadius() const { return radius; }

    double getArea() const {
        return M_PI * radius * radius;
    }

    double getCircumference() const {
        return 2 * M_PI * radius;
    }

    bool isLargerThan(const Circle& other) const {
        return radius > other.radius;
    }
};

int main() {
    Circle c1(5.0);
    Circle c2(3.0);

    cout << "Circle 1 Area: " << c1.getArea() << endl;
    cout << "Circle 2 Circumference: " << c2.getCircumference() << endl;
    cout << "Is Circle 1 larger than Circle 2? " 
         << (c1.isLargerThan(c2) ? "Yes" : "No") << endl;

    return 0;
}
