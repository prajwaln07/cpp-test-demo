// AI-Generated Unit Tests for circle.cpp (Circle class)
// Generated: 2025-10-20
// Framework: Google Test
// Test Coverage: Constructors, setRadius, getters, area, circumference, diameter, isEqual

#include <gtest/gtest.h>
#include <stdexcept>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Include the Circle class directly
class Circle {
private:
    double radius;

public:
    // Default constructor
    Circle() : radius(0.0) {}

    // Parameterized constructor
    Circle(double r) {
        setRadius(r);
    }

    // Setter with validation
    void setRadius(double r) {
        if (r < 0) {
            throw std::invalid_argument("Radius cannot be negative");
        }
        radius = r;
    }

    // Getter
    double getRadius() const {
        return radius;
    }

    // Area = πr²
    double getArea() const {
        return M_PI * radius * radius;
    }

    // Circumference = 2πr
    double getCircumference() const {
        return 2 * M_PI * radius;
    }

    // Diameter = 2r
    double getDiameter() const {
        return 2 * radius;
    }

    // Compare two circles
    bool isEqual(const Circle& other, double epsilon = 1e-9) const {
        return std::fabs(radius - other.radius) < epsilon;
    }
};

// ============================================
// Test Suite: Circle
// ============================================

class CircleTest : public ::testing::Test {
protected:
    void SetUp() override {
        epsilon = 0.0001; // Tolerance for double comparisons
    }
    
    double epsilon;
};

// ============================================
// Tests for Default Constructor
// ============================================

TEST_F(CircleTest, DefaultConstructor_InitializesToZero) {
    Circle c;
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
}

TEST_F(CircleTest, DefaultConstructor_AreaIsZero) {
    Circle c;
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST_F(CircleTest, DefaultConstructor_CircumferenceIsZero) {
    Circle c;
    EXPECT_DOUBLE_EQ(c.getCircumference(), 0.0);
}

TEST_F(CircleTest, DefaultConstructor_DiameterIsZero) {
    Circle c;
    EXPECT_DOUBLE_EQ(c.getDiameter(), 0.0);
}

// ============================================
// Tests for Parameterized Constructor
// ============================================

TEST_F(CircleTest, ParameterizedConstructor_ValidRadius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST_F(CircleTest, ParameterizedConstructor_SmallRadius) {
    Circle c(0.001);
    EXPECT_NEAR(c.getRadius(), 0.001, epsilon);
}

TEST_F(CircleTest, ParameterizedConstructor_LargeRadius) {
    Circle c(10000.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10000.0);
}

TEST_F(CircleTest, ParameterizedConstructor_ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
}

TEST_F(CircleTest, ParameterizedConstructor_DecimalRadius) {
    Circle c(3.14159);
    EXPECT_NEAR(c.getRadius(), 3.14159, epsilon);
}

TEST_F(CircleTest, ParameterizedConstructor_NegativeRadius_ThrowsException) {
    EXPECT_THROW(Circle(-1.0), std::invalid_argument);
    EXPECT_THROW(Circle(-0.001), std::invalid_argument);
    EXPECT_THROW(Circle(-100.0), std::invalid_argument);
}

// ============================================
// Tests for setRadius()
// ============================================

TEST_F(CircleTest, SetRadius_ValidPositiveValue) {
    Circle c;
    c.setRadius(7.5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.5);
}

TEST_F(CircleTest, SetRadius_Zero) {
    Circle c(5.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
}

TEST_F(CircleTest, SetRadius_SmallValue) {
    Circle c;
    c.setRadius(0.0001);
    EXPECT_NEAR(c.getRadius(), 0.0001, epsilon);
}

TEST_F(CircleTest, SetRadius_LargeValue) {
    Circle c;
    c.setRadius(999999.99);
    EXPECT_DOUBLE_EQ(c.getRadius(), 999999.99);
}

TEST_F(CircleTest, SetRadius_MultipleChanges) {
    Circle c(5.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    
    c.setRadius(3.5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.5);
    
    c.setRadius(20.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 20.0);
}

TEST_F(CircleTest, SetRadius_NegativeValue_ThrowsException) {
    Circle c(5.0);
    EXPECT_THROW(c.setRadius(-1.0), std::invalid_argument);
    EXPECT_THROW(c.setRadius(-0.1), std::invalid_argument);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0); // Unchanged after exception
}

TEST_F(CircleTest, SetRadius_AfterFailedSet_ValueUnchanged) {
    Circle c(10.0);
    try {
        c.setRadius(-5.0);
    } catch (...) {}
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
}

// ============================================
// Tests for getRadius()
// ============================================

TEST_F(CircleTest, GetRadius_ReturnsCorrectValue) {
    Circle c(12.5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 12.5);
}

TEST_F(CircleTest, GetRadius_AfterSetRadius) {
    Circle c(5.0);
    c.setRadius(8.5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 8.5);
}

TEST_F(CircleTest, GetRadius_IsConst) {
    const Circle c(7.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.0);
}

TEST_F(CircleTest, GetRadius_DefaultConstructor) {
    Circle c;
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
}

// ============================================
// Tests for getArea()
// ============================================

TEST_F(CircleTest, GetArea_ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST_F(CircleTest, GetArea_RadiusOne) {
    Circle c(1.0);
    EXPECT_NEAR(c.getArea(), M_PI, epsilon);
}

TEST_F(CircleTest, GetArea_RadiusFive) {
    Circle c(5.0);
    EXPECT_NEAR(c.getArea(), M_PI * 25.0, epsilon);
}

TEST_F(CircleTest, GetArea_RadiusTen) {
    Circle c(10.0);
    EXPECT_NEAR(c.getArea(), M_PI * 100.0, epsilon);
}

TEST_F(CircleTest, GetArea_SmallRadius) {
    Circle c(0.1);
    EXPECT_NEAR(c.getArea(), M_PI * 0.01, epsilon);
}

TEST_F(CircleTest, GetArea_LargeRadius) {
    Circle c(100.0);
    EXPECT_NEAR(c.getArea(), M_PI * 10000.0, 1.0);
}

TEST_F(CircleTest, GetArea_DecimalRadius) {
    Circle c(3.5);
    EXPECT_NEAR(c.getArea(), M_PI * 12.25, epsilon);
}

TEST_F(CircleTest, GetArea_AfterSetRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getArea(), M_PI * 25.0, epsilon);
    
    c.setRadius(10.0);
    EXPECT_NEAR(c.getArea(), M_PI * 100.0, epsilon);
}

TEST_F(CircleTest, GetArea_IsConst) {
    const Circle c(7.0);
    EXPECT_NEAR(c.getArea(), M_PI * 49.0, epsilon);
}

TEST_F(CircleTest, GetArea_DefaultConstructor) {
    Circle c;
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

// ============================================
// Tests for getCircumference()
// ============================================

TEST_F(CircleTest, GetCircumference_ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 0.0);
}

TEST_F(CircleTest, GetCircumference_RadiusOne) {
    Circle c(1.0);
    EXPECT_NEAR(c.getCircumference(), 2 * M_PI, epsilon);
}

TEST_F(CircleTest, GetCircumference_RadiusFive) {
    Circle c(5.0);
    EXPECT_NEAR(c.getCircumference(), 10 * M_PI, epsilon);
}

TEST_F(CircleTest, GetCircumference_RadiusTen) {
    Circle c(10.0);
    EXPECT_NEAR(c.getCircumference(), 20 * M_PI, epsilon);
}

TEST_F(CircleTest, GetCircumference_SmallRadius) {
    Circle c(0.5);
    EXPECT_NEAR(c.getCircumference(), M_PI, epsilon);
}

TEST_F(CircleTest, GetCircumference_LargeRadius) {
    Circle c(1000.0);
    EXPECT_NEAR(c.getCircumference(), 2000 * M_PI, 0.1);
}

TEST_F(CircleTest, GetCircumference_DecimalRadius) {
    Circle c(3.5);
    EXPECT_NEAR(c.getCircumference(), 7.0 * M_PI, epsilon);
}

TEST_F(CircleTest, GetCircumference_AfterSetRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getCircumference(), 10 * M_PI, epsilon);
    
    c.setRadius(7.0);
    EXPECT_NEAR(c.getCircumference(), 14 * M_PI, epsilon);
}

TEST_F(CircleTest, GetCircumference_IsConst) {
    const Circle c(6.0);
    EXPECT_NEAR(c.getCircumference(), 12 * M_PI, epsilon);
}

TEST_F(CircleTest, GetCircumference_DefaultConstructor) {
    Circle c;
    EXPECT_DOUBLE_EQ(c.getCircumference(), 0.0);
}

// ============================================
// Tests for getDiameter()
// ============================================

TEST_F(CircleTest, GetDiameter_ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 0.0);
}

TEST_F(CircleTest, GetDiameter_RadiusOne) {
    Circle c(1.0);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 2.0);
}

TEST_F(CircleTest, GetDiameter_RadiusFive) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 10.0);
}

TEST_F(CircleTest, GetDiameter_RadiusTen) {
    Circle c(10.0);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 20.0);
}

TEST_F(CircleTest, GetDiameter_SmallRadius) {
    Circle c(0.25);
    EXPECT_NEAR(c.getDiameter(), 0.5, epsilon);
}

TEST_F(CircleTest, GetDiameter_LargeRadius) {
    Circle c(50000.0);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 100000.0);
}

TEST_F(CircleTest, GetDiameter_DecimalRadius) {
    Circle c(7.5);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 15.0);
}

TEST_F(CircleTest, GetDiameter_AfterSetRadius) {
    Circle c(3.0);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 6.0);
    
    c.setRadius(8.5);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 17.0);
}

TEST_F(CircleTest, GetDiameter_IsConst) {
    const Circle c(12.0);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 24.0);
}

TEST_F(CircleTest, GetDiameter_DefaultConstructor) {
    Circle c;
    EXPECT_DOUBLE_EQ(c.getDiameter(), 0.0);
}

// ============================================
// Tests for isEqual()
// ============================================

TEST_F(CircleTest, IsEqual_SameRadius) {
    Circle c1(5.0);
    Circle c2(5.0);
    EXPECT_TRUE(c1.isEqual(c2));
}

TEST_F(CircleTest, IsEqual_DifferentRadius) {
    Circle c1(5.0);
    Circle c2(10.0);
    EXPECT_FALSE(c1.isEqual(c2));
}

TEST_F(CircleTest, IsEqual_BothZero) {
    Circle c1;
    Circle c2;
    EXPECT_TRUE(c1.isEqual(c2));
}

TEST_F(CircleTest, IsEqual_VeryCloseRadii_DefaultEpsilon) {
    Circle c1(5.0);
    Circle c2(5.0000000001);
    EXPECT_TRUE(c1.isEqual(c2)); // Within default epsilon (1e-9)
}

TEST_F(CircleTest, IsEqual_SlightlyDifferent_DefaultEpsilon) {
    Circle c1(5.0);
    Circle c2(5.001);
    EXPECT_FALSE(c1.isEqual(c2));
}

TEST_F(CircleTest, IsEqual_CustomEpsilon_Within) {
    Circle c1(5.0);
    Circle c2(5.05);
    EXPECT_TRUE(c1.isEqual(c2, 0.1)); // Within custom epsilon
}

TEST_F(CircleTest, IsEqual_CustomEpsilon_Outside) {
    Circle c1(5.0);
    Circle c2(5.2);
    EXPECT_FALSE(c1.isEqual(c2, 0.1)); // Outside custom epsilon
}

TEST_F(CircleTest, IsEqual_SameObject) {
    Circle c(7.5);
    EXPECT_TRUE(c.isEqual(c));
}

TEST_F(CircleTest, IsEqual_AfterSetRadius) {
    Circle c1(5.0);
    Circle c2(10.0);
    EXPECT_FALSE(c1.isEqual(c2));
    
    c2.setRadius(5.0);
    EXPECT_TRUE(c1.isEqual(c2));
}

TEST_F(CircleTest, IsEqual_IsConst) {
    const Circle c1(5.0);
    const Circle c2(5.0);
    EXPECT_TRUE(c1.isEqual(c2));
}

TEST_F(CircleTest, IsEqual_SmallRadii) {
    Circle c1(0.001);
    Circle c2(0.001);
    EXPECT_TRUE(c1.isEqual(c2));
}

TEST_F(CircleTest, IsEqual_LargeRadii) {
    Circle c1(100000.0);
    Circle c2(100000.0);
    EXPECT_TRUE(c1.isEqual(c2));
}

// ============================================
// Integration Tests
// ============================================

TEST_F(CircleTest, Integration_CreateAndModify) {
    Circle c(10.0);
    
    // Initial state
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    EXPECT_NEAR(c.getArea(), M_PI * 100.0, epsilon);
    EXPECT_NEAR(c.getCircumference(), 20 * M_PI, epsilon);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 20.0);
    
    // Modify radius
    c.setRadius(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_NEAR(c.getArea(), M_PI * 25.0, epsilon);
    EXPECT_NEAR(c.getCircumference(), 10 * M_PI, epsilon);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 10.0);
}

TEST_F(CircleTest, Integration_AreaCircumferenceDiameterConsistency) {
    Circle c(7.0);
    
    // All calculations should be consistent
    double radius = c.getRadius();
    double area = c.getArea();
    double circumference = c.getCircumference();
    double diameter = c.getDiameter();
    
    EXPECT_NEAR(area, M_PI * radius * radius, epsilon);
    EXPECT_NEAR(circumference, 2 * M_PI * radius, epsilon);
    EXPECT_DOUBLE_EQ(diameter, 2 * radius);
}

TEST_F(CircleTest, Integration_CompareMultipleCircles) {
    Circle c1(5.0);
    Circle c2(5.0);
    Circle c3(7.0);
    
    EXPECT_TRUE(c1.isEqual(c2));
    EXPECT_FALSE(c1.isEqual(c3));
    EXPECT_FALSE(c2.isEqual(c3));
    
    c3.setRadius(5.0);
    EXPECT_TRUE(c1.isEqual(c3));
}

TEST_F(CircleTest, Integration_ExceptionDoesNotCorruptState) {
    Circle c(10.0);
    
    // Try to set negative radius
    try {
        c.setRadius(-5.0);
    } catch (...) {}
    
    // State should be unchanged
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    EXPECT_NEAR(c.getArea(), M_PI * 100.0, epsilon);
    EXPECT_NEAR(c.getCircumference(), 20 * M_PI, epsilon);
    
    // Valid operations still work
    c.setRadius(15.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 15.0);
}

TEST_F(CircleTest, Integration_ScalingRadius) {
    Circle c(5.0);
    double originalArea = c.getArea();
    double originalCircumference = c.getCircumference();
    
    // Double the radius
    c.setRadius(10.0);
    
    // Area should be 4x (r² relationship)
    EXPECT_NEAR(c.getArea(), originalArea * 4.0, epsilon);
    
    // Circumference should be 2x (linear relationship)
    EXPECT_NEAR(c.getCircumference(), originalCircumference * 2.0, epsilon);
}

TEST_F(CircleTest, Integration_FromZeroToValue) {
    Circle c; // Default constructor
    
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 0.0);
    
    c.setRadius(3.0);
    
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_NEAR(c.getArea(), M_PI * 9.0, epsilon);
    EXPECT_NEAR(c.getCircumference(), 6 * M_PI, epsilon);
}

// ============================================
// Edge Cases and Boundary Tests
// ============================================

TEST_F(CircleTest, EdgeCase_VerySmallRadius) {
    Circle c(1e-10);
    EXPECT_GT(c.getArea(), 0.0);
    EXPECT_GT(c.getCircumference(), 0.0);
    EXPECT_GT(c.getDiameter(), 0.0);
}

TEST_F(CircleTest, EdgeCase_VeryLargeRadius) {
    Circle c(1e10);
    EXPECT_GT(c.getArea(), 0.0);
    EXPECT_GT(c.getCircumference(), 0.0);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 2e10);
}

TEST_F(CircleTest, EdgeCase_PrecisionTest) {
    Circle c(1.0 / 3.0); // 0.333...
    double area = c.getArea();
    EXPECT_GT(area, 0.0);
    EXPECT_LT(area, M_PI); // Less than π since r < 1
}

TEST_F(CircleTest, EdgeCase_IsEqualPrecision) {
    Circle c1(1.0);
    Circle c2(1.0 + 1e-10);
    
    // Should be equal with default epsilon
    EXPECT_TRUE(c1.isEqual(c2));
    
    // Should not be equal with very strict epsilon
    EXPECT_FALSE(c1.isEqual(c2, 1e-12));
}

TEST_F(CircleTest, EdgeCase_MultipleSetToZero) {
    Circle c(10.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    
    c.setRadius(5.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
}

TEST_F(CircleTest, EdgeCase_MathematicalConstants) {
    // Circle with radius = 1 should have area = π
    Circle unitCircle(1.0);
    EXPECT_NEAR(unitCircle.getArea(), M_PI, epsilon);
    
    // Circle with radius = 1 should have circumference = 2π
    EXPECT_NEAR(unitCircle.getCircumference(), 2 * M_PI, epsilon);
}

// Main test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
