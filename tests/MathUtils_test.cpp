// Comprehensive Unit Tests for MathUtils (random.cpp)
// Generated for PR #18
// Framework: Google Test
// Coverage: Statistical and mathematical utility functions

#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>

using namespace std;

// MathUtils class from random.cpp
class MathUtils {
public:
    static double mean(const vector<int>& nums);
    static double median(vector<int> nums);
    static int mode(const vector<int>& nums);
    static int gcd(int a, int b);
    static int lcm(int a, int b);
    static long long factorial(int n);
    static bool isPrime(int n);
};

// Test fixture
class MathUtilsTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// ============================================================================
// Tests for mean()
// ============================================================================

TEST_F(MathUtilsTest, Mean_NormalDataSet) {
    vector<int> data = {1, 2, 3, 4, 5};
    EXPECT_DOUBLE_EQ(MathUtils::mean(data), 3.0);
    
    vector<int> data2 = {10, 20, 30};
    EXPECT_DOUBLE_EQ(MathUtils::mean(data2), 20.0);
}

TEST_F(MathUtilsTest, Mean_SingleElement) {
    vector<int> data = {42};
    EXPECT_DOUBLE_EQ(MathUtils::mean(data), 42.0);
}

TEST_F(MathUtilsTest, Mean_NegativeNumbers) {
    vector<int> data = {-5, -10, -15};
    EXPECT_DOUBLE_EQ(MathUtils::mean(data), -10.0);
}

TEST_F(MathUtilsTest, Mean_MixedPositiveNegative) {
    vector<int> data = {-5, 0, 5, 10};
    EXPECT_DOUBLE_EQ(MathUtils::mean(data), 2.5);
}

TEST_F(MathUtilsTest, Mean_EmptyDataSet) {
    vector<int> data;
    EXPECT_THROW(MathUtils::mean(data), invalid_argument);
}

TEST_F(MathUtilsTest, Mean_LargeDataSet) {
    vector<int> data(1000, 5);
    EXPECT_DOUBLE_EQ(MathUtils::mean(data), 5.0);
}

// ============================================================================
// Tests for median()
// ============================================================================

TEST_F(MathUtilsTest, Median_OddElements) {
    vector<int> data = {1, 3, 5, 7, 9};
    EXPECT_DOUBLE_EQ(MathUtils::median(data), 5.0);
    
    vector<int> unsorted = {9, 1, 5, 3, 7};
    EXPECT_DOUBLE_EQ(MathUtils::median(unsorted), 5.0);
}

TEST_F(MathUtilsTest, Median_EvenElements) {
    vector<int> data = {1, 2, 3, 4};
    EXPECT_DOUBLE_EQ(MathUtils::median(data), 2.5);
    
    vector<int> data2 = {10, 20, 30, 40};
    EXPECT_DOUBLE_EQ(MathUtils::median(data2), 25.0);
}

TEST_F(MathUtilsTest, Median_SingleElement) {
    vector<int> data = {100};
    EXPECT_DOUBLE_EQ(MathUtils::median(data), 100.0);
}

TEST_F(MathUtilsTest, Median_TwoElements) {
    vector<int> data = {5, 15};
    EXPECT_DOUBLE_EQ(MathUtils::median(data), 10.0);
}

TEST_F(MathUtilsTest, Median_EmptyDataSet) {
    vector<int> data;
    EXPECT_THROW(MathUtils::median(data), invalid_argument);
}

TEST_F(MathUtilsTest, Median_DuplicateValues) {
    vector<int> data = {5, 5, 5, 5, 5};
    EXPECT_DOUBLE_EQ(MathUtils::median(data), 5.0);
}

// ============================================================================
// Tests for mode()
// ============================================================================

TEST_F(MathUtilsTest, Mode_SingleMode) {
    vector<int> data = {1, 2, 2, 3, 4};
    EXPECT_EQ(MathUtils::mode(data), 2);
    
    vector<int> data2 = {5, 5, 5, 1, 2, 3};
    EXPECT_EQ(MathUtils::mode(data2), 5);
}

TEST_F(MathUtilsTest, Mode_AllSameValues) {
    vector<int> data = {7, 7, 7, 7};
    EXPECT_EQ(MathUtils::mode(data), 7);
}

TEST_F(MathUtilsTest, Mode_AllUniqueValues) {
    vector<int> data = {1, 2, 3, 4, 5};
    EXPECT_EQ(MathUtils::mode(data), 1);
}

TEST_F(MathUtilsTest, Mode_EmptyDataSet) {
    vector<int> data;
    EXPECT_THROW(MathUtils::mode(data), invalid_argument);
}

TEST_F(MathUtilsTest, Mode_NegativeNumbers) {
    vector<int> data = {-5, -5, -3, -2};
    EXPECT_EQ(MathUtils::mode(data), -5);
}

// ============================================================================
// Tests for gcd()
// ============================================================================

TEST_F(MathUtilsTest, GCD_NormalCases) {
    EXPECT_EQ(MathUtils::gcd(48, 18), 6);
    EXPECT_EQ(MathUtils::gcd(100, 50), 50);
    EXPECT_EQ(MathUtils::gcd(17, 13), 1);
}

TEST_F(MathUtilsTest, GCD_OneIsZero) {
    EXPECT_EQ(MathUtils::gcd(0, 5), 5);
    EXPECT_EQ(MathUtils::gcd(10, 0), 10);
}

TEST_F(MathUtilsTest, GCD_BothZero) {
    EXPECT_THROW(MathUtils::gcd(0, 0), invalid_argument);
}

TEST_F(MathUtilsTest, GCD_SameNumbers) {
    EXPECT_EQ(MathUtils::gcd(25, 25), 25);
}

TEST_F(MathUtilsTest, GCD_Coprime) {
    EXPECT_EQ(MathUtils::gcd(7, 11), 1);
    EXPECT_EQ(MathUtils::gcd(13, 17), 1);
}

TEST_F(MathUtilsTest, GCD_LargeNumbers) {
    EXPECT_EQ(MathUtils::gcd(1071, 462), 21);
}

// ============================================================================
// Tests for lcm()
// ============================================================================

TEST_F(MathUtilsTest, LCM_NormalCases) {
    EXPECT_EQ(MathUtils::lcm(12, 15), 60);
    EXPECT_EQ(MathUtils::lcm(4, 6), 12);
    EXPECT_EQ(MathUtils::lcm(21, 6), 42);
}

TEST_F(MathUtilsTest, LCM_OneIsOne) {
    EXPECT_EQ(MathUtils::lcm(1, 5), 5);
    EXPECT_EQ(MathUtils::lcm(7, 1), 7);
}

TEST_F(MathUtilsTest, LCM_SameNumbers) {
    EXPECT_EQ(MathUtils::lcm(10, 10), 10);
}

TEST_F(MathUtilsTest, LCM_Coprime) {
    EXPECT_EQ(MathUtils::lcm(7, 11), 77);
    EXPECT_EQ(MathUtils::lcm(13, 17), 221);
}

TEST_F(MathUtilsTest, LCM_WithZero) {
    EXPECT_THROW(MathUtils::lcm(0, 5), invalid_argument);
    EXPECT_THROW(MathUtils::lcm(10, 0), invalid_argument);
}

TEST_F(MathUtilsTest, LCM_MultipleRelationship) {
    EXPECT_EQ(MathUtils::lcm(5, 15), 15);
    EXPECT_EQ(MathUtils::lcm(3, 12), 12);
}

// ============================================================================
// Tests for factorial()
// ============================================================================

TEST_F(MathUtilsTest, Factorial_SmallNumbers) {
    EXPECT_EQ(MathUtils::factorial(0), 1);
    EXPECT_EQ(MathUtils::factorial(1), 1);
    EXPECT_EQ(MathUtils::factorial(5), 120);
    EXPECT_EQ(MathUtils::factorial(6), 720);
}

TEST_F(MathUtilsTest, Factorial_Ten) {
    EXPECT_EQ(MathUtils::factorial(10), 3628800);
}

TEST_F(MathUtilsTest, Factorial_NegativeNumber) {
    EXPECT_THROW(MathUtils::factorial(-1), invalid_argument);
    EXPECT_THROW(MathUtils::factorial(-10), invalid_argument);
}

TEST_F(MathUtilsTest, Factorial_LargeNumber) {
    EXPECT_EQ(MathUtils::factorial(12), 479001600);
}

// ============================================================================
// Tests for isPrime()
// ============================================================================

TEST_F(MathUtilsTest, IsPrime_SmallPrimes) {
    EXPECT_TRUE(MathUtils::isPrime(2));
    EXPECT_TRUE(MathUtils::isPrime(3));
    EXPECT_TRUE(MathUtils::isPrime(5));
    EXPECT_TRUE(MathUtils::isPrime(7));
    EXPECT_TRUE(MathUtils::isPrime(11));
    EXPECT_TRUE(MathUtils::isPrime(13));
}

TEST_F(MathUtilsTest, IsPrime_NonPrimes) {
    EXPECT_FALSE(MathUtils::isPrime(4));
    EXPECT_FALSE(MathUtils::isPrime(6));
    EXPECT_FALSE(MathUtils::isPrime(8));
    EXPECT_FALSE(MathUtils::isPrime(9));
    EXPECT_FALSE(MathUtils::isPrime(10));
}

TEST_F(MathUtilsTest, IsPrime_EdgeCases) {
    EXPECT_FALSE(MathUtils::isPrime(0));
    EXPECT_FALSE(MathUtils::isPrime(1));
    EXPECT_FALSE(MathUtils::isPrime(-5));
}

TEST_F(MathUtilsTest, IsPrime_LargePrimes) {
    EXPECT_TRUE(MathUtils::isPrime(97));
    EXPECT_TRUE(MathUtils::isPrime(101));
}

TEST_F(MathUtilsTest, IsPrime_LargeNonPrimes) {
    EXPECT_FALSE(MathUtils::isPrime(100));
    EXPECT_FALSE(MathUtils::isPrime(99));
}

// ============================================================================
// Integration Tests
// ============================================================================

TEST_F(MathUtilsTest, Integration_GCDandLCM) {
    int a = 12, b = 18;
    int gcd_val = MathUtils::gcd(a, b);
    int lcm_val = MathUtils::lcm(a, b);
    
    EXPECT_EQ(gcd_val, 6);
    EXPECT_EQ(lcm_val, 36);
    EXPECT_EQ(gcd_val * lcm_val, a * b);
}

TEST_F(MathUtilsTest, Integration_StatisticalMeasures) {
    vector<int> data = {2, 3, 4, 3, 5, 3, 2};
    
    double mean_val = MathUtils::mean(data);
    double median_val = MathUtils::median(data);
    int mode_val = MathUtils::mode(data);
    
    EXPECT_NEAR(mean_val, 3.14, 0.1);
    EXPECT_DOUBLE_EQ(median_val, 3.0);
    EXPECT_EQ(mode_val, 3);
}

TEST_F(MathUtilsTest, Integration_FactorialAndPrime) {
    EXPECT_TRUE(MathUtils::isPrime(5));
    EXPECT_EQ(MathUtils::factorial(5), 120);
    
    EXPECT_TRUE(MathUtils::isPrime(7));
    EXPECT_EQ(MathUtils::factorial(7), 5040);
}

// Main test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}