#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    double divide(int a, int b);
    
    // Advanced math operations
    int power(int base, int exponent);
    int factorial(int n);
    double squareRoot(double x);
    bool isPrime(int n);
};

#endif // CALCULATOR_H
