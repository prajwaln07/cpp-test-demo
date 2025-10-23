#include <iostream>
#include <cmath>
using namespace std;

struct Roots {
    bool real;
    double root1, root2;
    double realPart, imagPart;
};

// Solve ax^2 + bx + c = 0
Roots solveQuadratic(double a, double b, double c) {
    Roots r;
    double discriminant = b*b - 4*a*c;

    if (discriminant >= 0) {
        r.real = true;
        r.root1 = (-b + sqrt(discriminant)) / (2*a);
        r.root2 = (-b - sqrt(discriminant)) / (2*a);
    } else {
        r.real = false;
        r.realPart = -b / (2*a);
        r.imagPart = sqrt(-discriminant) / (2*a);
    }
    return r;
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "Not a quadratic equation." << endl;
        return 0;
    }

    Roots r = solveQuadratic(a, b, c);

    if (r.real) {
        cout << "Roots are real: " << r.root1 << " and " << r.root2 << endl;
    } else {
        cout << "Roots are complex: "
             << r.realPart << " + " << r.imagPart << "i and "
             << r.realPart << " - " << r.imagPart << "i" << endl;
    }

    return 0;
}
