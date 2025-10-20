#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>

class Circle {
private:
    double radius;

public:
    // Default constructor
    Circle() : radius(0.0) {}

    // Parameterized constructor
    Circle(double r) {
        setRadius(r);
    }

    // Setter with validation
    void setRadius(double r) {
        if (r < 0) {
            throw std::invalid_argument("Radius cannot be negative");
        }
        radius = r;
    }

    // Getter
    double getRadius() const {
        return radius;
    }

    // Area = πr²
    double getArea() const {
        return M_PI * radius * radius;
    }

    // Circumference = 2πr
    double getCircumference() const {
        return 2 * M_PI * radius;
    }

    // Diameter = 2r
    double getDiameter() const {
        return 2 * radius;
    }

    // Compare two circles (useful for testing equality)
    bool isEqual(const Circle& other, double epsilon = 1e-9) const {
        return std::fabs(radius - other.radius) < epsilon;
    }
};

