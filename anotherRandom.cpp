#include <iostream>
#include <stdexcept>
using namespace std;

class MathUtils {
public:
    static int add(int a, int b) {
        return a + b;
    }

    static int subtract(int a, int b) {
        return a - b;
    }

    static int multiply(int a, int b) {
        return a * b;
    }

    static int divide(int a, int b) {
        if (b == 0)
            throw invalid_argument("Division by zero not allowed");
        return a / b;
    }

    static bool isEven(int n) {
        return n % 2 == 0;
    }

    static bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
};

int main() {
    int x = 10, y = 3;

    cout << "Add: " << MathUtils::add(x, y) << endl;
    cout << "Subtract: " << MathUtils::subtract(x, y) << endl;
    cout << "Multiply: " << MathUtils::multiply(x, y) << endl;
    cout << "Divide: " << MathUtils::divide(x, y) << endl;
    cout << "IsEven(" << x << "): " << MathUtils::isEven(x) << endl;
    cout << "IsPrime(" << y << "): " << MathUtils::isPrime(y) << endl;

    return 0;
}
