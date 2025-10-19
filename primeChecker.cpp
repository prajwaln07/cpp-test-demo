#include <iostream>
using namespace std;

bool isPrime(int number) {
    // Handle special cases
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    // Check for divisibility up to square root of number
    for (int i = 3; i * i <= number; i += 2) {
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