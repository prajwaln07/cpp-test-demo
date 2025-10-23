// Comprehensive Unit Tests for Factorial.cpp
// Generated for PR #18

#include <gtest/gtest.h>

using namespace std;

long long factorial(int n);

class FactorialTest : public ::testing::Test {};

TEST_F(FactorialTest, Factorial_BaseCase) {
    EXPECT_EQ(factorial(0), 1);
    EXPECT_EQ(factorial(1), 1);
}

TEST_F(FactorialTest, Factorial_SmallNumbers) {
    EXPECT_EQ(factorial(2), 2);
    EXPECT_EQ(factorial(3), 6);
    EXPECT_EQ(factorial(4), 24);
    EXPECT_EQ(factorial(5), 120);
}

TEST_F(FactorialTest, Factorial_MediumNumbers) {
    EXPECT_EQ(factorial(6), 720);
    EXPECT_EQ(factorial(7), 5040);
    EXPECT_EQ(factorial(10), 3628800);
}

TEST_F(FactorialTest, Factorial_LargeNumbers) {
    EXPECT_EQ(factorial(12), 479001600);
    EXPECT_EQ(factorial(15), 1307674368000);
}

TEST_F(FactorialTest, Factorial_RecursiveProperty) {
    // n! = n * (n-1)!
    int n = 6;
    EXPECT_EQ(factorial(n), n * factorial(n-1));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}