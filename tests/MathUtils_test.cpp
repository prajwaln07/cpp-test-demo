// AI-Generated Unit Tests for anotherRandom.cpp (MathUtils)
// Generated: 2025-10-19
// Framework: Google Test
// Test Coverage: add, subtract, multiply, divide, isEven, isPrime

#include <gtest/gtest.h>
#include <stdexcept>

// Include the class directly since it's not in a header
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
            throw std::invalid_argument("Division by zero not allowed");
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

// ============================================
// Test Suite: MathUtils
// ============================================

class MathUtilsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Common setup for all tests
    }
    
    void TearDown() override {
        // Common cleanup for all tests
    }
};

// ============================================
// Tests for add()
// ============================================

TEST_F(MathUtilsTest, Add_PositiveNumbers) {
    EXPECT_EQ(MathUtils::add(5, 3), 8);
    EXPECT_EQ(MathUtils::add(10, 20), 30);
    EXPECT_EQ(MathUtils::add(100, 200), 300);
}

TEST_F(MathUtilsTest, Add_NegativeNumbers) {
    EXPECT_EQ(MathUtils::add(-5, -3), -8);
    EXPECT_EQ(MathUtils::add(-10, -20), -30);
}

TEST_F(MathUtilsTest, Add_MixedSigns) {
    EXPECT_EQ(MathUtils::add(5, -3), 2);
    EXPECT_EQ(MathUtils::add(-5, 3), -2);
    EXPECT_EQ(MathUtils::add(-10, 10), 0);
}

TEST_F(MathUtilsTest, Add_WithZero) {
    EXPECT_EQ(MathUtils::add(0, 0), 0);
    EXPECT_EQ(MathUtils::add(5, 0), 5);
    EXPECT_EQ(MathUtils::add(0, 5), 5);
}

TEST_F(MathUtilsTest, Add_LargeNumbers) {
    EXPECT_EQ(MathUtils::add(1000000, 2000000), 3000000);
}

// ============================================
// Tests for subtract()
// ============================================

TEST_F(MathUtilsTest, Subtract_PositiveNumbers) {
    EXPECT_EQ(MathUtils::subtract(10, 3), 7);
    EXPECT_EQ(MathUtils::subtract(50, 20), 30);
    EXPECT_EQ(MathUtils::subtract(100, 100), 0);
}

TEST_F(MathUtilsTest, Subtract_NegativeNumbers) {
    EXPECT_EQ(MathUtils::subtract(-10, -3), -7);
    EXPECT_EQ(MathUtils::subtract(-5, -10), 5);
}

TEST_F(MathUtilsTest, Subtract_MixedSigns) {
    EXPECT_EQ(MathUtils::subtract(10, -5), 15);
    EXPECT_EQ(MathUtils::subtract(-10, 5), -15);
}

TEST_F(MathUtilsTest, Subtract_WithZero) {
    EXPECT_EQ(MathUtils::subtract(0, 0), 0);
    EXPECT_EQ(MathUtils::subtract(10, 0), 10);
    EXPECT_EQ(MathUtils::subtract(0, 10), -10);
}

TEST_F(MathUtilsTest, Subtract_ResultingInNegative) {
    EXPECT_EQ(MathUtils::subtract(3, 10), -7);
}

// ============================================
// Tests for multiply()
// ============================================

TEST_F(MathUtilsTest, Multiply_PositiveNumbers) {
    EXPECT_EQ(MathUtils::multiply(5, 3), 15);
    EXPECT_EQ(MathUtils::multiply(10, 10), 100);
    EXPECT_EQ(MathUtils::multiply(7, 8), 56);
}

TEST_F(MathUtilsTest, Multiply_NegativeNumbers) {
    EXPECT_EQ(MathUtils::multiply(-5, -3), 15);
    EXPECT_EQ(MathUtils::multiply(-10, -10), 100);
}

TEST_F(MathUtilsTest, Multiply_MixedSigns) {
    EXPECT_EQ(MathUtils::multiply(5, -3), -15);
    EXPECT_EQ(MathUtils::multiply(-5, 3), -15);
}

TEST_F(MathUtilsTest, Multiply_WithZero) {
    EXPECT_EQ(MathUtils::multiply(0, 0), 0);
    EXPECT_EQ(MathUtils::multiply(5, 0), 0);
    EXPECT_EQ(MathUtils::multiply(0, 5), 0);
    EXPECT_EQ(MathUtils::multiply(-5, 0), 0);
}

TEST_F(MathUtilsTest, Multiply_WithOne) {
    EXPECT_EQ(MathUtils::multiply(5, 1), 5);
    EXPECT_EQ(MathUtils::multiply(1, 5), 5);
    EXPECT_EQ(MathUtils::multiply(-5, 1), -5);
}

TEST_F(MathUtilsTest, Multiply_LargeNumbers) {
    EXPECT_EQ(MathUtils::multiply(1000, 1000), 1000000);
}

// ============================================
// Tests for divide()
// ============================================

TEST_F(MathUtilsTest, Divide_PositiveNumbers) {
    EXPECT_EQ(MathUtils::divide(10, 2), 5);
    EXPECT_EQ(MathUtils::divide(20, 4), 5);
    EXPECT_EQ(MathUtils::divide(100, 10), 10);
}

TEST_F(MathUtilsTest, Divide_NegativeNumbers) {
    EXPECT_EQ(MathUtils::divide(-10, -2), 5);
    EXPECT_EQ(MathUtils::divide(-20, -4), 5);
}

TEST_F(MathUtilsTest, Divide_MixedSigns) {
    EXPECT_EQ(MathUtils::divide(10, -2), -5);
    EXPECT_EQ(MathUtils::divide(-10, 2), -5);
}

TEST_F(MathUtilsTest, Divide_ResultingInZero) {
    EXPECT_EQ(MathUtils::divide(0, 5), 0);
    EXPECT_EQ(MathUtils::divide(0, -5), 0);
}

TEST_F(MathUtilsTest, Divide_IntegerDivision) {
    // Integer division truncates
    EXPECT_EQ(MathUtils::divide(10, 3), 3);
    EXPECT_EQ(MathUtils::divide(7, 2), 3);
    EXPECT_EQ(MathUtils::divide(5, 2), 2);
}

TEST_F(MathUtilsTest, Divide_ByZero_ThrowsException) {
    EXPECT_THROW(MathUtils::divide(10, 0), std::invalid_argument);
    EXPECT_THROW(MathUtils::divide(-10, 0), std::invalid_argument);
    EXPECT_THROW(MathUtils::divide(0, 0), std::invalid_argument);
}

TEST_F(MathUtilsTest, Divide_ByOne) {
    EXPECT_EQ(MathUtils::divide(10, 1), 10);
    EXPECT_EQ(MathUtils::divide(-10, 1), -10);
}

// ============================================
// Tests for isEven()
// ============================================

TEST_F(MathUtilsTest, IsEven_PositiveEvenNumbers) {
    EXPECT_TRUE(MathUtils::isEven(0));
    EXPECT_TRUE(MathUtils::isEven(2));
    EXPECT_TRUE(MathUtils::isEven(4));
    EXPECT_TRUE(MathUtils::isEven(10));
    EXPECT_TRUE(MathUtils::isEven(100));
    EXPECT_TRUE(MathUtils::isEven(1000));
}

TEST_F(MathUtilsTest, IsEven_PositiveOddNumbers) {
    EXPECT_FALSE(MathUtils::isEven(1));
    EXPECT_FALSE(MathUtils::isEven(3));
    EXPECT_FALSE(MathUtils::isEven(5));
    EXPECT_FALSE(MathUtils::isEven(99));
    EXPECT_FALSE(MathUtils::isEven(1001));
}

TEST_F(MathUtilsTest, IsEven_NegativeEvenNumbers) {
    EXPECT_TRUE(MathUtils::isEven(-2));
    EXPECT_TRUE(MathUtils::isEven(-4));
    EXPECT_TRUE(MathUtils::isEven(-10));
    EXPECT_TRUE(MathUtils::isEven(-100));
}

TEST_F(MathUtilsTest, IsEven_NegativeOddNumbers) {
    EXPECT_FALSE(MathUtils::isEven(-1));
    EXPECT_FALSE(MathUtils::isEven(-3));
    EXPECT_FALSE(MathUtils::isEven(-5));
    EXPECT_FALSE(MathUtils::isEven(-99));
}

TEST_F(MathUtilsTest, IsEven_Zero) {
    EXPECT_TRUE(MathUtils::isEven(0));
}

// ============================================
// Tests for isPrime()
// ============================================

TEST_F(MathUtilsTest, IsPrime_SmallPrimes) {
    EXPECT_TRUE(MathUtils::isPrime(2));
    EXPECT_TRUE(MathUtils::isPrime(3));
    EXPECT_TRUE(MathUtils::isPrime(5));
    EXPECT_TRUE(MathUtils::isPrime(7));
    EXPECT_TRUE(MathUtils::isPrime(11));
    EXPECT_TRUE(MathUtils::isPrime(13));
}

TEST_F(MathUtilsTest, IsPrime_LargerPrimes) {
    EXPECT_TRUE(MathUtils::isPrime(17));
    EXPECT_TRUE(MathUtils::isPrime(19));
    EXPECT_TRUE(MathUtils::isPrime(23));
    EXPECT_TRUE(MathUtils::isPrime(29));
    EXPECT_TRUE(MathUtils::isPrime(97));
}

TEST_F(MathUtilsTest, IsPrime_CompositeNumbers) {
    EXPECT_FALSE(MathUtils::isPrime(4));
    EXPECT_FALSE(MathUtils::isPrime(6));
    EXPECT_FALSE(MathUtils::isPrime(8));
    EXPECT_FALSE(MathUtils::isPrime(9));
    EXPECT_FALSE(MathUtils::isPrime(10));
    EXPECT_FALSE(MathUtils::isPrime(15));
    EXPECT_FALSE(MathUtils::isPrime(20));
    EXPECT_FALSE(MathUtils::isPrime(100));
}

TEST_F(MathUtilsTest, IsPrime_EdgeCases) {
    EXPECT_FALSE(MathUtils::isPrime(0));
    EXPECT_FALSE(MathUtils::isPrime(1));
    EXPECT_FALSE(MathUtils::isPrime(-1));
    EXPECT_FALSE(MathUtils::isPrime(-5));
}

TEST_F(MathUtilsTest, IsPrime_SquareNumbers) {
    EXPECT_FALSE(MathUtils::isPrime(4));   // 2²
    EXPECT_FALSE(MathUtils::isPrime(9));   // 3²
    EXPECT_FALSE(MathUtils::isPrime(16));  // 4²
    EXPECT_FALSE(MathUtils::isPrime(25));  // 5²
    EXPECT_FALSE(MathUtils::isPrime(49));  // 7²
}

// ============================================
// Integration Tests
// ============================================

TEST_F(MathUtilsTest, Integration_CombinedOperations) {
    // (10 + 5) * 2 / 3 = 10
    int result = MathUtils::add(10, 5);
    result = MathUtils::multiply(result, 2);
    result = MathUtils::divide(result, 3);
    EXPECT_EQ(result, 10);
}

TEST_F(MathUtilsTest, Integration_CheckPrimeAndEven) {
    // 2 is the only even prime number
    EXPECT_TRUE(MathUtils::isPrime(2));
    EXPECT_TRUE(MathUtils::isEven(2));
    
    // Other primes are odd
    EXPECT_TRUE(MathUtils::isPrime(7));
    EXPECT_FALSE(MathUtils::isEven(7));
}

// Main test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
