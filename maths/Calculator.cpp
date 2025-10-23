#include <iostream>
using namespace std;

// Addition
int add(int a, int b) {
    return a + b;
}

// Subtraction
int subtract(int a, int b) {
    return a - b;
}

// Multiplication
int multiply(int a, int b) {
    return a * b;
}

// Division
double divide(int a, int b) {
    if (b == 0) {
        cout << "Division by zero is not allowed!" << endl;
        return 0;
    }
    return (double)a / b;
}

// Modulus
int modulus(int a, int b) {
    if (b == 0) {
        cout << "Modulus by zero is not allowed!" << endl;
        return 0;
    }
    return a % b;
}

int main() {
    int a, b;
    char op;

    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter operator (+, -, *, /, %): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> b;

    switch(op) {
        case '+': cout << "Result: " << add(a, b); break;
        case '-': cout << "Result: " << subtract(a, b); break;
        case '*': cout << "Result: " << multiply(a, b); break;
        case '/': cout << "Result: " << divide(a, b); break;
        case '%': cout << "Result: " << modulus(a, b); break;
        default: cout << "Invalid operator!";
    }

    return 0;
}
