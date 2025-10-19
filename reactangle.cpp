#include <iostream>
#include <stdexcept>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        if (l <= 0 || w <= 0)
            throw invalid_argument("Length and width must be positive");
        length = l;
        width = w;
    }

    void setLength(double l) {
        if (l <= 0)
            throw invalid_argument("Length must be positive");
        length = l;
    }

    void setWidth(double w) {
        if (w <= 0)
            throw invalid_argument("Width must be positive");
        width = w;
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }

    double getArea() const {
        return length * width;
    }

    double getPerimeter() const {
        return 2 * (length + width);
    }

    bool isSquare() const {
        return length == width;
    }
};

int main() {
    Rectangle r(5.0, 10.0);
    cout << "Length: " << r.getLength() << endl;
    cout << "Width: " << r.getWidth() << endl;
    cout << "Area: " << r.getArea() << endl;
    cout << "Perimeter: " << r.getPerimeter() << endl;
    cout << "Is Square: " << (r.isSquare() ? "Yes" : "No") << endl;

    return 0;
}
