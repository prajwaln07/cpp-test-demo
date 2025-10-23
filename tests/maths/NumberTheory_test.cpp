#include <gtest/gtest.h>
#include "../../maths/NumberTheory.cpp"
#include <limits>

// Test fixture for NumberTheory tests
class NumberTheoryTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};

// ==================== Factorial Tests ====================

TEST_F(NumberTheoryTest, Factorial_Zero_ReturnsOne) {
    EXPECT_EQ(factorial(0), 1);
}

TEST_F(NumberTheoryTest, Factorial_One_ReturnsOne) {
    EXPECT_EQ(factorial(1), 1);
}

TEST_F(NumberTheoryTest, Factorial_SmallPositiveNumbers) {
    EXPECT_EQ(factorial(2), 2);
    EXPECT_EQ(factorial(3), 6);
    EXPECT_EQ(factorial(4), 24);
    EXPECT_EQ(factorial(5), 120);
    EXPECT_EQ(factorial(6), 720);
}

TEST_F(NumberTheoryTest, Factorial_Ten_Returns3628800) {
    EXPECT_EQ(factorial(10), 3628800);
}

TEST_F(NumberTheoryTest, Factorial_Twelve_Returns479001600) {
    EXPECT_EQ(factorial(12), 479001600);
}

TEST_F(NumberTheoryTest, Factorial_LargeNumber_Fifteen) {
    EXPECT_EQ(factorial(15), 1307674368000LL);
}

TEST_F(NumberTheoryTest, Factorial_Twenty_ValidResult) {
    // 20! = 2432902008176640000
    EXPECT_EQ(factorial(20), 2432902008176640000LL);
}

// ==================== nPr (Permutations) Tests ====================

TEST_F(NumberTheoryTest, NPr_RGreaterThanN_ReturnsZero) {
    EXPECT_EQ(nPr(3, 5), 0);
    EXPECT_EQ(nPr(5, 10), 0);
    EXPECT_EQ(nPr(0, 1), 0);
}

TEST_F(NumberTheoryTest, NPr_REqualsZero_ReturnsOne) {
    EXPECT_EQ(nPr(5, 0), 1);
    EXPECT_EQ(nPr(10, 0), 1);
    EXPECT_EQ(nPr(100, 0), 1);
}

TEST_F(NumberTheoryTest, NPr_REqualsN_ReturnsFactorialN) {
    EXPECT_EQ(nPr(5, 5), factorial(5));
    EXPECT_EQ(nPr(7, 7), factorial(7));
    EXPECT_EQ(nPr(10, 10), factorial(10));
}

TEST_F(NumberTheoryTest, NPr_BasicCases) {
    EXPECT_EQ(nPr(5, 2), 20);   // 5!/(5-2)! = 120/6 = 20
    EXPECT_EQ(nPr(6, 3), 120);  // 6!/(6-3)! = 720/6 = 120
    EXPECT_EQ(nPr(4, 2), 12);   // 4!/(4-2)! = 24/2 = 12
}

TEST_F(NumberTheoryTest, NPr_REqualsOne_ReturnsN) {
    EXPECT_EQ(nPr(5, 1), 5);
    EXPECT_EQ(nPr(10, 1), 10);
    EXPECT_EQ(nPr(100, 1), 100);
}

TEST_F(NumberTheoryTest, NPr_LargerValues) {
    EXPECT_EQ(nPr(10, 3), 720);   // 10!/7! = 720
    EXPECT_EQ(nPr(8, 5), 6720);   // 8!/3! = 6720
}

TEST_F(NumberTheoryTest, NPr_EdgeCase_ZeroZero) {
    EXPECT_EQ(nPr(0, 0), 1);  // 0!/0! = 1
}

// ==================== nCr (Combinations) Tests ====================

TEST_F(NumberTheoryTest, NCr_RGreaterThanN_ReturnsZero) {
    EXPECT_EQ(nCr(3, 5), 0);
    EXPECT_EQ(nCr(5, 10), 0);
    EXPECT_EQ(nCr(0, 1), 0);
}

TEST_F(NumberTheoryTest, NCr_REqualsZero_ReturnsOne) {
    EXPECT_EQ(nCr(5, 0), 1);
    EXPECT_EQ(nCr(10, 0), 1);
    EXPECT_EQ(nCr(100, 0), 1);
}

TEST_F(NumberTheoryTest, NCr_REqualsN_ReturnsOne) {
    EXPECT_EQ(nCr(5, 5), 1);
    EXPECT_EQ(nCr(10, 10), 1);
    EXPECT_EQ(nCr(20, 20), 1);
}

TEST_F(NumberTheoryTest, NCr_BasicCases) {
    EXPECT_EQ(nCr(5, 2), 10);   // 5!/(2!*3!) = 120/(2*6) = 10
    EXPECT_EQ(nCr(6, 3), 20);   // 6!/(3!*3!) = 720/(6*6) = 20
    EXPECT_EQ(nCr(4, 2), 6);    // 4!/(2!*2!) = 24/(2*2) = 6
}

TEST_F(NumberTheoryTest, NCr_REqualsOne_ReturnsN) {
    EXPECT_EQ(nCr(5, 1), 5);
    EXPECT_EQ(nCr(10, 1), 10);
    EXPECT_EQ(nCr(100, 1), 100);
}

TEST_F(NumberTheoryTest, NCr_SymmetryProperty) {
    // nCr(n,r) = nCr(n, n-r)
    EXPECT_EQ(nCr(10, 3), nCr(10, 7));
    EXPECT_EQ(nCr(8, 2), nCr(8, 6));
    EXPECT_EQ(nCr(12, 5), nCr(12, 7));
}

TEST_F(NumberTheoryTest, NCr_LargerValues) {
    EXPECT_EQ(nCr(10, 5), 252);  // 10!/(5!*5!) = 252
    EXPECT_EQ(nCr(9, 4), 126);   // 9!/(4!*5!) = 126
}

TEST_F(NumberTheoryTest, NCr_EdgeCase_ZeroZero) {
    EXPECT_EQ(nCr(0, 0), 1);  // 0!/(0!*0!) = 1
}

TEST_F(NumberTheoryTest, NCr_PascalTriangleProperty) {
    // nCr(n,r) = nCr(n-1,r-1) + nCr(n-1,r)
    EXPECT_EQ(nCr(5, 2), nCr(4, 1) + nCr(4, 2));
    EXPECT_EQ(nCr(6, 3), nCr(5, 2) + nCr(5, 3));
}

// ==================== GCD Tests ====================

TEST_F(NumberTheoryTest, GCD_SameNumbers_ReturnsSameNumber) {
    EXPECT_EQ(gcd(5, 5), 5);
    EXPECT_EQ(gcd(10, 10), 10);
    EXPECT_EQ(gcd(100, 100), 100);
}

TEST_F(NumberTheoryTest, GCD_OneNumberIsZero_ReturnsOther) {
    EXPECT_EQ(gcd(5, 0), 5);
    EXPECT_EQ(gcd(0, 10), 10);
}

TEST_F(NumberTheoryTest, GCD_BothZero_ReturnsZero) {
    EXPECT_EQ(gcd(0, 0), 0);
}

TEST_F(NumberTheoryTest, GCD_CoprimeNumbers_ReturnsOne) {
    EXPECT_EQ(gcd(7, 11), 1);
    EXPECT_EQ(gcd(13, 17), 1);
    EXPECT_EQ(gcd(9, 16), 1);
}

TEST_F(NumberTheoryTest, GCD_BasicCases) {
    EXPECT_EQ(gcd(12, 8), 4);
    EXPECT_EQ(gcd(54, 24), 6);
    EXPECT_EQ(gcd(48, 18), 6);
}

TEST_F(NumberTheoryTest, GCD_OneIsMultipleOfOther) {
    EXPECT_EQ(gcd(15, 5), 5);
    EXPECT_EQ(gcd(20, 10), 10);
    EXPECT_EQ(gcd(100, 25), 25);
}

TEST_F(NumberTheoryTest, GCD_LargeNumbers) {
    EXPECT_EQ(gcd(1071, 462), 21);
    EXPECT_EQ(gcd(270, 192), 6);
}

TEST_F(NumberTheoryTest, GCD_Commutative) {
    // gcd(a,b) = gcd(b,a)
    EXPECT_EQ(gcd(12, 8), gcd(8, 12));
    EXPECT_EQ(gcd(54, 24), gcd(24, 54));
}

TEST_F(NumberTheoryTest, GCD_PowersOfTwo) {
    EXPECT_EQ(gcd(16, 32), 16);
    EXPECT_EQ(gcd(64, 128), 64);
}

TEST_F(NumberTheoryTest, GCD_ConsecutiveNumbers_ReturnsOne) {
    EXPECT_EQ(gcd(5, 6), 1);
    EXPECT_EQ(gcd(99, 100), 1);
    EXPECT_EQ(gcd(1000, 1001), 1);
}

// ==================== LCM Tests ====================

TEST_F(NumberTheoryTest, LCM_SameNumbers_ReturnsSameNumber) {
    EXPECT_EQ(lcm(5, 5), 5);
    EXPECT_EQ(lcm(10, 10), 10);
    EXPECT_EQ(lcm(100, 100), 100);
}

TEST_F(NumberTheoryTest, LCM_OneIsMultipleOfOther) {
    EXPECT_EQ(lcm(5, 15), 15);
    EXPECT_EQ(lcm(10, 20), 20);
    EXPECT_EQ(lcm(25, 100), 100);
}

TEST_F(NumberTheoryTest, LCM_CoprimeNumbers_ReturnsProduct) {
    EXPECT_EQ(lcm(7, 11), 77);
    EXPECT_EQ(lcm(3, 5), 15);
    EXPECT_EQ(lcm(13, 17), 221);
}

TEST_F(NumberTheoryTest, LCM_BasicCases) {
    EXPECT_EQ(lcm(4, 6), 12);
    EXPECT_EQ(lcm(12, 18), 36);
    EXPECT_EQ(lcm(15, 20), 60);
}

TEST_F(NumberTheoryTest, LCM_Commutative) {
    // lcm(a,b) = lcm(b,a)
    EXPECT_EQ(lcm(12, 8), lcm(8, 12));
    EXPECT_EQ(lcm(15, 20), lcm(20, 15));
}

TEST_F(NumberTheoryTest, LCM_WithOne) {
    EXPECT_EQ(lcm(1, 5), 5);
    EXPECT_EQ(lcm(10, 1), 10);
}

TEST_F(NumberTheoryTest, LCM_PowersOfTwo) {
    EXPECT_EQ(lcm(8, 16), 16);
    EXPECT_EQ(lcm(32, 64), 64);
}

TEST_F(NumberTheoryTest, LCM_LargerNumbers) {
    EXPECT_EQ(lcm(12, 15), 60);
    EXPECT_EQ(lcm(21, 28), 84);
}

TEST_F(NumberTheoryTest, LCM_GCD_Relationship) {
    // lcm(a,b) * gcd(a,b) = a * b
    int a = 12, b = 18;
    EXPECT_EQ(lcm(a, b) * gcd(a, b), a * b);
    
    a = 15; b = 25;
    EXPECT_EQ(lcm(a, b) * gcd(a, b), a * b);
}

// ==================== isPrime Tests ====================

TEST_F(NumberTheoryTest, IsPrime_NegativeNumbers_ReturnsFalse) {
    EXPECT_FALSE(isPrime(-1));
    EXPECT_FALSE(isPrime(-5));
    EXPECT_FALSE(isPrime(-100));
}

TEST_F(NumberTheoryTest, IsPrime_ZeroAndOne_ReturnsFalse) {
    EXPECT_FALSE(isPrime(0));
    EXPECT_FALSE(isPrime(1));
}

TEST_F(NumberTheoryTest, IsPrime_Two_ReturnsTrue) {
    EXPECT_TRUE(isPrime(2));
}

TEST_F(NumberTheoryTest, IsPrime_SmallPrimes_ReturnsTrue) {
    EXPECT_TRUE(isPrime(3));
    EXPECT_TRUE(isPrime(5));
    EXPECT_TRUE(isPrime(7));
    EXPECT_TRUE(isPrime(11));
    EXPECT_TRUE(isPrime(13));
    EXPECT_TRUE(isPrime(17));
    EXPECT_TRUE(isPrime(19));
    EXPECT_TRUE(isPrime(23));
}

TEST_F(NumberTheoryTest, IsPrime_SmallComposites_ReturnsFalse) {
    EXPECT_FALSE(isPrime(4));
    EXPECT_FALSE(isPrime(6));
    EXPECT_FALSE(isPrime(8));
    EXPECT_FALSE(isPrime(9));
    EXPECT_FALSE(isPrime(10));
    EXPECT_FALSE(isPrime(12));
    EXPECT_FALSE(isPrime(15));
}

TEST_F(NumberTheoryTest, IsPrime_PerfectSquares_ReturnsFalse) {
    EXPECT_FALSE(isPrime(4));   // 2²
    EXPECT_FALSE(isPrime(9));   // 3²
    EXPECT_FALSE(isPrime(16));  // 4²
    EXPECT_FALSE(isPrime(25));  // 5²
    EXPECT_FALSE(isPrime(49));  // 7²
    EXPECT_FALSE(isPrime(121)); // 11²
}

TEST_F(NumberTheoryTest, IsPrime_LargePrimes_ReturnsTrue) {
    EXPECT_TRUE(isPrime(29));
    EXPECT_TRUE(isPrime(31));
    EXPECT_TRUE(isPrime(37));
    EXPECT_TRUE(isPrime(41));
    EXPECT_TRUE(isPrime(43));
    EXPECT_TRUE(isPrime(47));
    EXPECT_TRUE(isPrime(97));
}

TEST_F(NumberTheoryTest, IsPrime_LargeComposites_ReturnsFalse) {
    EXPECT_FALSE(isPrime(51));  // 3 * 17
    EXPECT_FALSE(isPrime(91));  // 7 * 13
    EXPECT_FALSE(isPrime(100)); // 10 * 10
}

TEST_F(NumberTheoryTest, IsPrime_EvenNumbersGreaterThanTwo_ReturnsFalse) {
    EXPECT_FALSE(isPrime(14));
    EXPECT_FALSE(isPrime(22));
    EXPECT_FALSE(isPrime(50));
    EXPECT_FALSE(isPrime(100));
}

TEST_F(NumberTheoryTest, IsPrime_MultiplesOfThree_ReturnsFalse) {
    EXPECT_FALSE(isPrime(9));
    EXPECT_FALSE(isPrime(15));
    EXPECT_FALSE(isPrime(21));
    EXPECT_FALSE(isPrime(27));
}

TEST_F(NumberTheoryTest, IsPrime_TwinPrimes) {
    // Twin primes (differ by 2)
    EXPECT_TRUE(isPrime(11));
    EXPECT_TRUE(isPrime(13));
    
    EXPECT_TRUE(isPrime(17));
    EXPECT_TRUE(isPrime(19));
    
    EXPECT_TRUE(isPrime(29));
    EXPECT_TRUE(isPrime(31));
}

// ==================== Integration Tests ====================

TEST_F(NumberTheoryTest, Integration_FactorialAndPermutations) {
    // nPr should use factorial
    int n = 5, r = 3;
    EXPECT_EQ(nPr(n, r), factorial(n) / factorial(n - r));
}

TEST_F(NumberTheoryTest, Integration_FactorialAndCombinations) {
    // nCr should use factorial
    int n = 6, r = 2;
    EXPECT_EQ(nCr(n, r), factorial(n) / (factorial(r) * factorial(n - r)));
}

TEST_F(NumberTheoryTest, Integration_GCDandLCM) {
    // For any two numbers: lcm(a,b) * gcd(a,b) = a * b
    int a = 24, b = 36;
    EXPECT_EQ(lcm(a, b) * gcd(a, b), a * b);
}

TEST_F(NumberTheoryTest, Integration_PrimeAndGCD) {
    // GCD of two different prime numbers should be 1
    EXPECT_TRUE(isPrime(7));
    EXPECT_TRUE(isPrime(11));
    EXPECT_EQ(gcd(7, 11), 1);
}

TEST_F(NumberTheoryTest, Integration_PrimeAndLCM) {
    // LCM of two different prime numbers should be their product
    int p1 = 5, p2 = 7;
    EXPECT_TRUE(isPrime(p1));
    EXPECT_TRUE(isPrime(p2));
    EXPECT_EQ(lcm(p1, p2), p1 * p2);
}

TEST_F(NumberTheoryTest, Integration_PermutationGreaterThanCombination) {
    // For same n and r (r > 0), nPr >= nCr
    EXPECT_GE(nPr(5, 2), nCr(5, 2));
    EXPECT_GE(nPr(7, 3), nCr(7, 3));
}

TEST_F(NumberTheoryTest, Integration_MultipleOperations) {
    // Complex scenario
    int a = 12, b = 8;
    
    int g = gcd(a, b);           // 4
    int l = lcm(a, b);           // 24
    long long f_a = factorial(a); // 479001600
    
    EXPECT_EQ(g, 4);
    EXPECT_EQ(l, 24);
    EXPECT_EQ(f_a, 479001600);
    EXPECT_EQ(g * l, a * b);
}

// ==================== Edge Cases and Boundary Tests ====================

TEST_F(NumberTheoryTest, EdgeCase_AllFunctions_WithOne) {
    EXPECT_EQ(factorial(1), 1);
    EXPECT_EQ(nPr(1, 1), 1);
    EXPECT_EQ(nCr(1, 1), 1);
    EXPECT_EQ(gcd(1, 1), 1);
    EXPECT_EQ(lcm(1, 1), 1);
    EXPECT_FALSE(isPrime(1));
}

TEST_F(NumberTheoryTest, EdgeCase_GCDandLCM_WithZero) {
    EXPECT_EQ(gcd(10, 0), 10);
    EXPECT_EQ(gcd(0, 10), 10);
    // Note: lcm with 0 would cause issues, so we avoid that case
}

TEST_F(NumberTheoryTest, EdgeCase_NPr_NCr_BoundaryConditions) {
    // When r = 0
    EXPECT_EQ(nPr(10, 0), 1);
    EXPECT_EQ(nCr(10, 0), 1);
    
    // When r = n
    EXPECT_EQ(nPr(10, 10), factorial(10));
    EXPECT_EQ(nCr(10, 10), 1);
    
    // When r > n
    EXPECT_EQ(nPr(5, 10), 0);
    EXPECT_EQ(nCr(5, 10), 0);
}

TEST_F(NumberTheoryTest, BoundaryCase_FactorialGrowth) {
    // Factorial grows rapidly
    EXPECT_GT(factorial(10), factorial(9));
    EXPECT_GT(factorial(9), factorial(8));
    EXPECT_EQ(factorial(10), factorial(9) * 10);
}

TEST_F(NumberTheoryTest, BoundaryCase_PrimeNumbers_Around100) {
    EXPECT_TRUE(isPrime(97));   // Largest prime < 100
    EXPECT_FALSE(isPrime(98));
    EXPECT_FALSE(isPrime(99));
    EXPECT_FALSE(isPrime(100));
}

// ==================== Property-Based Tests ====================

TEST_F(NumberTheoryTest, Property_GCD_Reflexive) {
    // gcd(a,a) = a
    EXPECT_EQ(gcd(5, 5), 5);
    EXPECT_EQ(gcd(17, 17), 17);
}

TEST_F(NumberTheoryTest, Property_GCD_Symmetric) {
    // gcd(a,b) = gcd(b,a)
    EXPECT_EQ(gcd(12, 18), gcd(18, 12));
    EXPECT_EQ(gcd(7, 21), gcd(21, 7));
}

TEST_F(NumberTheoryTest, Property_LCM_Reflexive) {
    // lcm(a,a) = a
    EXPECT_EQ(lcm(5, 5), 5);
    EXPECT_EQ(lcm(17, 17), 17);
}

TEST_F(NumberTheoryTest, Property_LCM_Symmetric) {
    // lcm(a,b) = lcm(b,a)
    EXPECT_EQ(lcm(12, 18), lcm(18, 12));
    EXPECT_EQ(lcm(7, 21), lcm(21, 7));
}

TEST_F(NumberTheoryTest, Property_NCr_Symmetry) {
    // nCr(n,r) = nCr(n,n-r)
    EXPECT_EQ(nCr(10, 3), nCr(10, 7));
    EXPECT_EQ(nCr(8, 2), nCr(8, 6));
}

TEST_F(NumberTheoryTest, Property_Factorial_Recursive) {
    // n! = n * (n-1)!
    EXPECT_EQ(factorial(5), 5 * factorial(4));
    EXPECT_EQ(factorial(7), 7 * factorial(6));
}

// ==================== Main Function ====================

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
