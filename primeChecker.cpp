#include <iostream>
using namespace std;
void printPascalTriangle(int n) {
    for (int line = 0; line < n; line++) {
        int number = 1;
        for (int i = 0; i <= line; i++) {
            cout << number << " ";
            number = number * (line - i) / (i + 1);
        }
        cout << endl;
    }
}
bool isPrime(int number) {
    // Handle special cases
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    // Check for divisibIility up to square root of number
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
bool isDivisibleBy3And5(int number) {
    return (number % 3 == 0 && number % 5 == 0);
}
bool isPrimeOverLoading(int number,int xyz) {
    // Handle special cases
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    // Check for divisibility up to square root of number
    for (int i = 3; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    cout << "Enter a number to check if it's prime: ";
    cin >> num;

    if (isPrime(num)) {
        cout << num << " is a prime number" << endl;
    } else {
        cout << num << " is not a prime number" << endl;
    }

    return 0;
}