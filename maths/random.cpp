#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stdexcept>
using namespace std;

class MathUtils {
public:
    static double mean(const vector<int>& nums) {
        if (nums.empty())
            throw invalid_argument("Empty data set");
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        return sum / nums.size();
    }

    static double median(vector<int> nums) {
        if (nums.empty())
            throw invalid_argument("Empty data set");
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n % 2 == 0)
            return (nums[n/2 - 1] + nums[n/2]) / 2.0;
        return nums[n/2];
    }

    static int mode(const vector<int>& nums) {
        if (nums.empty())
            throw invalid_argument("Empty data set");
        map<int, int> freq;
        for (int n : nums) freq[n]++;
        int mode = nums[0];
        int maxCount = 0;
        for (auto& p : freq) {
            if (p.second > maxCount) {
                maxCount = p.second;
                mode = p.first;
            }
        }
        return mode;
    }

    static int gcd(int a, int b) {
        if (a == 0 && b == 0)
            throw invalid_argument("Undefined GCD for 0 and 0");
        return b == 0 ? a : gcd(b, a % b);
    }

    static int lcm(int a, int b) {
        if (a == 0 || b == 0)
            throw invalid_argument("LCM undefined for zero");
        return abs(a * b) / gcd(a, b);
    }

    static long long factorial(int n) {
        if (n < 0)
            throw invalid_argument("Negative number not allowed");
        if (n == 0 || n == 1) return 1;
        long long result = 1;
        for (int i = 2; i <= n; i++)
            result *= i;
        return result;
    }

    static bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }
};

int main() {
    vector<int> data = {2, 3, 4, 3, 5, 3, 2};

    cout << "Mean: " << MathUtils::mean(data) << endl;
    cout << "Median: " << MathUtils::median(data) << endl;
    cout << "Mode: " << MathUtils::mode(data) << endl;

    cout << "GCD(48, 18): " << MathUtils::gcd(48, 18) << endl;
    cout << "LCM(12, 15): " << MathUtils::lcm(12, 15) << endl;

    cout << "Factorial(5): " << MathUtils::factorial(5) << endl;
    cout << "Is 19 prime? " << (MathUtils::isPrime(19) ? "Yes" : "No") << endl;

    return 0;
}
