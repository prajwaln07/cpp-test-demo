#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Triangle {
private:
    double a, b, c;

    bool isValid(double a, double b, double c) const {
        return a + b > c && a + c > b && b + c > a;
    }

public:
    Triangle(double side1, double side2, double side3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0)
            throw invalid_argument("Sides must be positive");
        if (!isValid(side1, side2, side3))
            throw invalid_argument("Invalid triangle sides");
        a = side1;
        b = side2;
        c = side3;
    }

    double getPerimeter() const {
        return a + b + c;
    }

    double getArea() const {
        double s = getPerimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    bool isEquilateral() const {
        return a == b && b == c;
    }

    bool isIsosceles() const {
        return (a == b || b == c || a == c);
    }
};

int main() {
    Triangle t(3.0, 4.0, 5.0);

    cout << "Perimeter: " << t.getPerimeter() << endl;
    cout << "Area: " << t.getArea() << endl;
    cout << "Is Equilateral: " << (t.isEquilateral() ? "Yes" : "No") << endl;
    cout << "Is Isosceles: " << (t.isIsosceles() ? "Yes" : "No") << endl;

    return 0;
}
