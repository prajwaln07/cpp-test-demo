#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int digits = to_string(n).size();
    int sum = 0, temp = n;
    while (temp) {
        int d = temp % 10;
        sum += pow(d, digits);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    cin >> n;
    cout << (isArmstrong(n) ? "Armstrong" : "Not Armstrong");
    return 0;
}
