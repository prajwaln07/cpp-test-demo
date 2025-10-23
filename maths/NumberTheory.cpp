#include <iostream>
using namespace std;

// Factorial
long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

// Permutations nPr
long long nPr(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / factorial(n - r);
}

// Combinations nCr
long long nCr(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Greatest Common Divisor
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Least Common Multiple
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// Prime check
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << "Factorial of " << a << ": " << factorial(a) << endl;
    cout << "nPr (" << a << "," << b << "): " << nPr(a, b) << endl;
    cout << "nCr (" << a << "," << b << "): " << nCr(a, b) << endl;
    cout << "GCD(" << a << "," << b << "): " << gcd(a, b) << endl;
    cout << "LCM(" << a << "," << b << "): " << lcm(a, b) << endl;
    cout << a << " is " << (isPrime(a) ? "prime" : "not prime") << endl;
    cout << b << " is " << (isPrime(b) ? "prime" : "not prime") << endl;

    return 0;
}
