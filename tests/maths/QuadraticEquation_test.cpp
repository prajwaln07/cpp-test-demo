#include <gtest/gtest.h>
#include "../../maths/QuadraticEquation.cpp"
#include <cmath>

// Test fixture for QuadraticEquation tests
class QuadraticEquationTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }

    // Helper function to compare double values with tolerance
    bool nearlyEqual(double a, double b, double epsilon = 0.0001) {
        return std::abs(a - b) < epsilon;
    }
};

// ==================== Real Roots Tests ====================

TEST_F(QuadraticEquationTest, SolveQuadratic_TwoDistinctRealRoots) {
    // x^2 - 5x + 6 = 0, roots are 3 and 2
    Roots r = solveQuadratic(1, -5, 6);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 3.0) || nearlyEqual(r.root1, 2.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 3.0) || nearlyEqual(r.root2, 2.0));
    EXPECT_NE(r.root1, r.root2);
}

TEST_F(QuadraticEquationTest, SolveQuadratic_TwoEqualRealRoots) {
    // x^2 - 4x + 4 = 0, roots are 2 and 2 (discriminant = 0)
    Roots r = solveQuadratic(1, -4, 4);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 2.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 2.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_PositiveRoots) {
    // x^2 - 7x + 10 = 0, roots are 5 and 2
    Roots r = solveQuadratic(1, -7, 10);
    
    EXPECT_TRUE(r.real);
    EXPECT_GT(r.root1, 0);
    EXPECT_GT(r.root2, 0);
}

TEST_F(QuadraticEquationTest, SolveQuadratic_NegativeRoots) {
    // x^2 + 7x + 10 = 0, roots are -5 and -2
    Roots r = solveQuadratic(1, 7, 10);
    
    EXPECT_TRUE(r.real);
    EXPECT_LT(r.root1, 0);
    EXPECT_LT(r.root2, 0);
}

TEST_F(QuadraticEquationTest, SolveQuadratic_MixedSignRoots) {
    // x^2 - x - 6 = 0, roots are 3 and -2
    Roots r = solveQuadratic(1, -1, -6);
    
    EXPECT_TRUE(r.real);
    // One root should be positive, one negative
    EXPECT_TRUE((r.root1 > 0 && r.root2 < 0) || (r.root1 < 0 && r.root2 > 0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_ZeroAsRoot) {
    // x^2 - 5x = 0, roots are 5 and 0
    Roots r = solveQuadratic(1, -5, 0);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 5.0) || nearlyEqual(r.root1, 0.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 5.0) || nearlyEqual(r.root2, 0.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_BothRootsZero) {
    // x^2 = 0, both roots are 0
    Roots r = solveQuadratic(1, 0, 0);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 0.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 0.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_LeadingCoefficientGreaterThanOne) {
    // 2x^2 - 8x + 6 = 0, simplifies to x^2 - 4x + 3 = 0, roots are 3 and 1
    Roots r = solveQuadratic(2, -8, 6);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 3.0) || nearlyEqual(r.root1, 1.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 3.0) || nearlyEqual(r.root2, 1.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_NegativeLeadingCoefficient) {
    // -x^2 + 5x - 6 = 0, equivalent to x^2 - 5x + 6 = 0, roots are 3 and 2
    Roots r = solveQuadratic(-1, 5, -6);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 3.0) || nearlyEqual(r.root1, 2.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 3.0) || nearlyEqual(r.root2, 2.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_LargeCoefficients) {
    // 100x^2 - 500x + 600 = 0, simplifies to x^2 - 5x + 6 = 0, roots are 3 and 2
    Roots r = solveQuadratic(100, -500, 600);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 3.0) || nearlyEqual(r.root1, 2.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 3.0) || nearlyEqual(r.root2, 2.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_FractionalCoefficients) {
    // 0.5x^2 - 2.5x + 3 = 0, equivalent to x^2 - 5x + 6 = 0, roots are 3 and 2
    Roots r = solveQuadratic(0.5, -2.5, 3);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 3.0) || nearlyEqual(r.root1, 2.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 3.0) || nearlyEqual(r.root2, 2.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_VerySmallDiscriminant) {
    // Discriminant very close to 0, should still return real roots
    Roots r = solveQuadratic(1, -2.0001, 1);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, r.root2, 0.01));
}

// ==================== Complex Roots Tests ====================

TEST_F(QuadraticEquationTest, SolveQuadratic_ComplexRoots_BasicCase) {
    // x^2 + 1 = 0, roots are ±i
    Roots r = solveQuadratic(1, 0, 1);
    
    EXPECT_FALSE(r.real);
    EXPECT_TRUE(nearlyEqual(r.realPart, 0.0));
    EXPECT_TRUE(nearlyEqual(r.imagPart, 1.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_ComplexRoots_WithRealPart) {
    // x^2 - 2x + 2 = 0, roots are 1±i
    Roots r = solveQuadratic(1, -2, 2);
    
    EXPECT_FALSE(r.real);
    EXPECT_TRUE(nearlyEqual(r.realPart, 1.0));
    EXPECT_TRUE(nearlyEqual(r.imagPart, 1.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_ComplexRoots_LargerImaginaryPart) {
    // x^2 + 4 = 0, roots are ±2i
    Roots r = solveQuadratic(1, 0, 4);
    
    EXPECT_FALSE(r.real);
    EXPECT_TRUE(nearlyEqual(r.realPart, 0.0));
    EXPECT_TRUE(nearlyEqual(r.imagPart, 2.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_ComplexRoots_NegativeDiscriminant) {
    // x^2 + x + 1 = 0, discriminant = 1 - 4 = -3
    Roots r = solveQuadratic(1, 1, 1);
    
    EXPECT_FALSE(r.real);
    EXPECT_TRUE(nearlyEqual(r.realPart, -0.5));
    EXPECT_GT(r.imagPart, 0);
}

TEST_F(QuadraticEquationTest, SolveQuadratic_ComplexRoots_LargeNegativeDiscriminant) {
    // x^2 + 100 = 0, roots are ±10i
    Roots r = solveQuadratic(1, 0, 100);
    
    EXPECT_FALSE(r.real);
    EXPECT_TRUE(nearlyEqual(r.realPart, 0.0));
    EXPECT_TRUE(nearlyEqual(r.imagPart, 10.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_ComplexRoots_WithAllCoefficients) {
    // 2x^2 + 4x + 5 = 0, roots are -1±0.5i
    Roots r = solveQuadratic(2, 4, 5);
    
    EXPECT_FALSE(r.real);
    EXPECT_TRUE(nearlyEqual(r.realPart, -1.0));
    EXPECT_GT(r.imagPart, 0);
}

TEST_F(QuadraticEquationTest, SolveQuadratic_ComplexRoots_NegativeLeadingCoeff) {
    // -x^2 - 1 = 0, equivalent to x^2 + 1 = 0, roots are ±i
    Roots r = solveQuadratic(-1, 0, -1);
    
    EXPECT_FALSE(r.real);
    EXPECT_TRUE(nearlyEqual(r.realPart, 0.0));
    EXPECT_TRUE(nearlyEqual(r.imagPart, 1.0));
}

// ==================== Discriminant Edge Cases ====================

TEST_F(QuadraticEquationTest, SolveQuadratic_DiscriminantZero_PerfectSquare) {
    // x^2 - 6x + 9 = 0, (x-3)^2 = 0, root is 3
    Roots r = solveQuadratic(1, -6, 9);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 3.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 3.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_DiscriminantZero_NegativeRoot) {
    // x^2 + 6x + 9 = 0, (x+3)^2 = 0, root is -3
    Roots r = solveQuadratic(1, 6, 9);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, -3.0));
    EXPECT_TRUE(nearlyEqual(r.root2, -3.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_LargePositiveDiscriminant) {
    // x^2 - 100 = 0, roots are ±10
    Roots r = solveQuadratic(1, 0, -100);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 10.0) || nearlyEqual(r.root1, -10.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 10.0) || nearlyEqual(r.root2, -10.0));
}

// ==================== Special Cases ====================

TEST_F(QuadraticEquationTest, SolveQuadratic_BCoeffZero_RealRoots) {
    // x^2 - 9 = 0, roots are ±3
    Roots r = solveQuadratic(1, 0, -9);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(std::abs(r.root1), 3.0));
    EXPECT_TRUE(nearlyEqual(std::abs(r.root2), 3.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_BCoeffZero_ComplexRoots) {
    // x^2 + 9 = 0, roots are ±3i
    Roots r = solveQuadratic(1, 0, 9);
    
    EXPECT_FALSE(r.real);
    EXPECT_TRUE(nearlyEqual(r.realPart, 0.0));
    EXPECT_TRUE(nearlyEqual(r.imagPart, 3.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_CCoeffZero) {
    // x^2 + 5x = 0, roots are 0 and -5
    Roots r = solveQuadratic(1, 5, 0);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 0.0) || nearlyEqual(r.root1, -5.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 0.0) || nearlyEqual(r.root2, -5.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_OnlyACoeff) {
    // x^2 = 0, both roots are 0
    Roots r = solveQuadratic(1, 0, 0);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 0.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 0.0));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_FractionalRoots) {
    // 2x^2 - 3x + 1 = 0, roots are 1 and 0.5
    Roots r = solveQuadratic(2, -3, 1);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 1.0) || nearlyEqual(r.root1, 0.5));
    EXPECT_TRUE(nearlyEqual(r.root2, 1.0) || nearlyEqual(r.root2, 0.5));
}

TEST_F(QuadraticEquationTest, SolveQuadratic_IrrationalRoots) {
    // x^2 - 2 = 0, roots are ±√2
    Roots r = solveQuadratic(1, 0, -2);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(std::abs(r.root1), std::sqrt(2.0)));
    EXPECT_TRUE(nearlyEqual(std::abs(r.root2), std::sqrt(2.0)));
}

// ==================== Verification Tests ====================

TEST_F(QuadraticEquationTest, Verify_RealRoots_SatisfyEquation) {
    // x^2 - 5x + 6 = 0, roots are 3 and 2
    double a = 1, b = -5, c = 6;
    Roots r = solveQuadratic(a, b, c);
    
    EXPECT_TRUE(r.real);
    
    // Verify root1 satisfies equation: a*x^2 + b*x + c ≈ 0
    double result1 = a * r.root1 * r.root1 + b * r.root1 + c;
    EXPECT_TRUE(nearlyEqual(result1, 0.0));
    
    // Verify root2 satisfies equation
    double result2 = a * r.root2 * r.root2 + b * r.root2 + c;
    EXPECT_TRUE(nearlyEqual(result2, 0.0));
}

TEST_F(QuadraticEquationTest, Verify_RootsSum_EqualsMinusBOverA) {
    // Vieta's formula: root1 + root2 = -b/a
    double a = 2, b = -8, c = 6;
    Roots r = solveQuadratic(a, b, c);
    
    EXPECT_TRUE(r.real);
    double sum = r.root1 + r.root2;
    double expectedSum = -b / a;
    EXPECT_TRUE(nearlyEqual(sum, expectedSum));
}

TEST_F(QuadraticEquationTest, Verify_RootsProduct_EqualsCOverA) {
    // Vieta's formula: root1 * root2 = c/a
    double a = 2, b = -8, c = 6;
    Roots r = solveQuadratic(a, b, c);
    
    EXPECT_TRUE(r.real);
    double product = r.root1 * r.root2;
    double expectedProduct = c / a;
    EXPECT_TRUE(nearlyEqual(product, expectedProduct));
}

TEST_F(QuadraticEquationTest, Verify_ComplexRoots_ConjugatePair) {
    // Complex roots should be conjugates: a+bi and a-bi
    Roots r = solveQuadratic(1, -2, 5);
    
    EXPECT_FALSE(r.real);
    // The roots are realPart + imagPart*i and realPart - imagPart*i
    // Both should have same real part
    EXPECT_TRUE(nearlyEqual(r.realPart, 1.0));
    EXPECT_GT(r.imagPart, 0);
}

// ==================== Symmetry Tests ====================

TEST_F(QuadraticEquationTest, Symmetry_PositiveAndNegativeC) {
    // x^2 - c and x^2 + c should give symmetric results
    Roots r1 = solveQuadratic(1, 0, -4);  // Real roots
    Roots r2 = solveQuadratic(1, 0, 4);   // Complex roots
    
    EXPECT_TRUE(r1.real);
    EXPECT_FALSE(r2.real);
}

TEST_F(QuadraticEquationTest, Symmetry_RootsAreOpposite) {
    // x^2 - a^2 = 0, roots are ±a
    Roots r = solveQuadratic(1, 0, -16);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, -r.root2) || nearlyEqual(r.root2, -r.root1));
}

// ==================== Stress Tests ====================

TEST_F(QuadraticEquationTest, Stress_VeryLargeCoefficients) {
    // 1000x^2 - 5000x + 6000 = 0
    Roots r = solveQuadratic(1000, -5000, 6000);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 3.0) || nearlyEqual(r.root1, 2.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 3.0) || nearlyEqual(r.root2, 2.0));
}

TEST_F(QuadraticEquationTest, Stress_VerySmallCoefficients) {
    // 0.001x^2 - 0.005x + 0.006 = 0
    Roots r = solveQuadratic(0.001, -0.005, 0.006);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, 3.0) || nearlyEqual(r.root1, 2.0));
    EXPECT_TRUE(nearlyEqual(r.root2, 3.0) || nearlyEqual(r.root2, 2.0));
}

TEST_F(QuadraticEquationTest, Stress_VeryCloseRoots) {
    // Roots very close to each other but not equal
    Roots r = solveQuadratic(1, -4.001, 4);
    
    EXPECT_TRUE(r.real);
    EXPECT_TRUE(nearlyEqual(r.root1, r.root2, 0.1));
}

// ==================== Integration Tests ====================

TEST_F(QuadraticEquationTest, Integration_MultipleEquations) {
    // Solve multiple equations and verify all work correctly
    Roots r1 = solveQuadratic(1, -5, 6);   // Real: 3, 2
    Roots r2 = solveQuadratic(1, 0, 1);    // Complex: ±i
    Roots r3 = solveQuadratic(1, -4, 4);   // Real: 2, 2
    
    EXPECT_TRUE(r1.real);
    EXPECT_FALSE(r2.real);
    EXPECT_TRUE(r3.real);
    
    EXPECT_TRUE(nearlyEqual(r3.root1, r3.root2));
}

TEST_F(QuadraticEquationTest, Integration_RealToComplex_Transition) {
    // As discriminant goes from positive to negative, should transition from real to complex
    Roots r1 = solveQuadratic(1, -4, 3);   // Discriminant = 16-12 = 4 > 0
    Roots r2 = solveQuadratic(1, -4, 4);   // Discriminant = 16-16 = 0
    Roots r3 = solveQuadratic(1, -4, 5);   // Discriminant = 16-20 = -4 < 0
    
    EXPECT_TRUE(r1.real);
    EXPECT_TRUE(r2.real);
    EXPECT_FALSE(r3.real);
}

// ==================== Main Function ====================

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
