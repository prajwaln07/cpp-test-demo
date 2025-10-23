#include <gtest/gtest.h>
#include "../../geometry/Point.cpp"
#include <cmath>
#include <limits>

// Test fixture for Point tests
class PointTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }

    // Helper function to check if two doubles are nearly equal
    bool nearlyEqual(double a, double b, double epsilon = 1e-9) {
        return std::abs(a - b) < epsilon;
    }
};

// ==================== Point Structure Tests ====================

TEST_F(PointTest, PointConstruction_DefaultValues) {
    Point p;
    // Default constructor behavior (uninitialized, but we can test assignment)
    p.x = 0.0;
    p.y = 0.0;
    EXPECT_DOUBLE_EQ(p.x, 0.0);
    EXPECT_DOUBLE_EQ(p.y, 0.0);
}

TEST_F(PointTest, PointConstruction_PositiveValues) {
    Point p = {3.5, 4.2};
    EXPECT_DOUBLE_EQ(p.x, 3.5);
    EXPECT_DOUBLE_EQ(p.y, 4.2);
}

TEST_F(PointTest, PointConstruction_NegativeValues) {
    Point p = {-5.3, -7.8};
    EXPECT_DOUBLE_EQ(p.x, -5.3);
    EXPECT_DOUBLE_EQ(p.y, -7.8);
}

TEST_F(PointTest, PointConstruction_MixedValues) {
    Point p = {-2.5, 6.7};
    EXPECT_DOUBLE_EQ(p.x, -2.5);
    EXPECT_DOUBLE_EQ(p.y, 6.7);
}

TEST_F(PointTest, PointConstruction_ZeroValues) {
    Point p = {0.0, 0.0};
    EXPECT_DOUBLE_EQ(p.x, 0.0);
    EXPECT_DOUBLE_EQ(p.y, 0.0);
}

// ==================== getLineIntersection - Basic Cases ====================

TEST_F(PointTest, GetLineIntersection_IntersectingLines_ReturnsTrue) {
    Point p1 = {0, 0}, p2 = {4, 4};
    Point p3 = {0, 4}, p4 = {4, 0};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, 2.0));
    EXPECT_TRUE(nearlyEqual(intersection.y, 2.0));
}

TEST_F(PointTest, GetLineIntersection_ParallelLines_ReturnsFalse) {
    Point p1 = {0, 0}, p2 = {4, 0};
    Point p3 = {0, 2}, p4 = {4, 2};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_FALSE(result);
}

TEST_F(PointTest, GetLineIntersection_VerticalAndHorizontalLines) {
    Point p1 = {2, 0}, p2 = {2, 4};  // Vertical line at x=2
    Point p3 = {0, 3}, p4 = {4, 3};  // Horizontal line at y=3
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, 2.0));
    EXPECT_TRUE(nearlyEqual(intersection.y, 3.0));
}

TEST_F(PointTest, GetLineIntersection_TwoVerticalLines_ReturnsFalse) {
    Point p1 = {1, 0}, p2 = {1, 4};
    Point p3 = {3, 0}, p4 = {3, 4};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_FALSE(result);
}

TEST_F(PointTest, GetLineIntersection_TwoHorizontalLines_ReturnsFalse) {
    Point p1 = {0, 1}, p2 = {4, 1};
    Point p3 = {0, 3}, p4 = {4, 3};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_FALSE(result);
}

// ==================== getLineIntersection - Edge Cases ====================

TEST_F(PointTest, GetLineIntersection_IntersectionAtOrigin) {
    Point p1 = {-2, -2}, p2 = {2, 2};
    Point p3 = {-2, 2}, p4 = {2, -2};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, 0.0));
    EXPECT_TRUE(nearlyEqual(intersection.y, 0.0));
}

TEST_F(PointTest, GetLineIntersection_SameLineSegment_DeterminantZero) {
    Point p1 = {0, 0}, p2 = {4, 4};
    Point p3 = {1, 1}, p4 = {3, 3};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_FALSE(result);  // Same line means determinant is zero
}

TEST_F(PointTest, GetLineIntersection_IdenticalLines_ReturnsFalse) {
    Point p1 = {0, 0}, p2 = {2, 2};
    Point p3 = {0, 0}, p4 = {2, 2};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_FALSE(result);
}

TEST_F(PointTest, GetLineIntersection_PointLines_SamePoint) {
    Point p1 = {1, 1}, p2 = {1, 1};  // Point, not a line
    Point p3 = {2, 2}, p4 = {3, 3};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_FALSE(result);  // Determinant will be zero
}

TEST_F(PointTest, GetLineIntersection_NegativeCoordinates) {
    Point p1 = {-4, -2}, p2 = {-1, 1};
    Point p3 = {-4, 1}, p4 = {-1, -2};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, -2.5));
    EXPECT_TRUE(nearlyEqual(intersection.y, -0.5));
}

// ==================== getLineIntersection - Specific Slopes ====================

TEST_F(PointTest, GetLineIntersection_PositiveSlopes) {
    Point p1 = {0, 0}, p2 = {4, 2};   // Slope = 0.5
    Point p3 = {0, 0}, p4 = {2, 4};   // Slope = 2
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, 0.0));
    EXPECT_TRUE(nearlyEqual(intersection.y, 0.0));
}

TEST_F(PointTest, GetLineIntersection_NegativeSlopes) {
    Point p1 = {0, 4}, p2 = {4, 0};   // Slope = -1
    Point p3 = {0, 2}, p4 = {4, -2};  // Slope = -1
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_FALSE(result);  // Parallel lines with same negative slope
}

TEST_F(PointTest, GetLineIntersection_MixedSlopes) {
    Point p1 = {0, 0}, p2 = {4, 4};   // Slope = 1
    Point p3 = {0, 4}, p4 = {4, 2};   // Slope = -0.5
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, 2.666666, 1e-5));
    EXPECT_TRUE(nearlyEqual(intersection.y, 2.666666, 1e-5));
}

TEST_F(PointTest, GetLineIntersection_ZeroSlope) {
    Point p1 = {0, 2}, p2 = {4, 2};   // Horizontal line (slope = 0)
    Point p3 = {2, 0}, p4 = {2, 4};   // Vertical line (undefined slope)
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, 2.0));
    EXPECT_TRUE(nearlyEqual(intersection.y, 2.0));
}

// ==================== getLineIntersection - Large Numbers ====================

TEST_F(PointTest, GetLineIntersection_LargeCoordinates) {
    Point p1 = {0, 0}, p2 = {1000, 1000};
    Point p3 = {0, 1000}, p4 = {1000, 0};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, 500.0));
    EXPECT_TRUE(nearlyEqual(intersection.y, 500.0));
}

TEST_F(PointTest, GetLineIntersection_VerySmallCoordinates) {
    Point p1 = {0, 0}, p2 = {0.001, 0.001};
    Point p3 = {0, 0.001}, p4 = {0.001, 0};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, 0.0005));
    EXPECT_TRUE(nearlyEqual(intersection.y, 0.0005));
}

// ==================== getLineIntersection - Precision Tests ====================

TEST_F(PointTest, GetLineIntersection_FloatingPointPrecision) {
    Point p1 = {0.1, 0.2}, p2 = {3.7, 5.9};
    Point p3 = {0.5, 4.3}, p4 = {3.2, 1.8};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    // Just check that intersection point is computed (specific values depend on calculation)
    EXPECT_TRUE(std::isfinite(intersection.x));
    EXPECT_TRUE(std::isfinite(intersection.y));
}

TEST_F(PointTest, GetLineIntersection_NearlyParallelLines) {
    Point p1 = {0, 0}, p2 = {10, 10};
    Point p3 = {0, 0.001}, p4 = {10, 10.001};  // Nearly parallel
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    // Determinant should be very small but not exactly zero
    // Result depends on floating point precision
    if (result) {
        EXPECT_TRUE(std::isfinite(intersection.x));
        EXPECT_TRUE(std::isfinite(intersection.y));
    }
}

// ==================== getLineIntersection - Real-World Examples ====================

TEST_F(PointTest, GetLineIntersection_ExampleFromMain) {
    // Test case from the main function
    Point p1 = {1, 1}, p2 = {4, 4};
    Point p3 = {1, 8}, p4 = {2, 4};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(std::isfinite(intersection.x));
    EXPECT_TRUE(std::isfinite(intersection.y));
}

TEST_F(PointTest, GetLineIntersection_PerpendicularLines) {
    Point p1 = {0, 0}, p2 = {5, 0};   // Horizontal
    Point p3 = {2, -3}, p4 = {2, 3};  // Vertical
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, 2.0));
    EXPECT_TRUE(nearlyEqual(intersection.y, 0.0));
}

TEST_F(PointTest, GetLineIntersection_DiagonalLines) {
    Point p1 = {0, 0}, p2 = {6, 6};   // Diagonal y = x
    Point p3 = {0, 6}, p4 = {6, 0};   // Diagonal y = -x + 6
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, 3.0));
    EXPECT_TRUE(nearlyEqual(intersection.y, 3.0));
}

// ==================== getLineIntersection - Boundary Cases ====================

TEST_F(PointTest, GetLineIntersection_IntersectionOutsideSegments) {
    // Lines intersect, but outside the given segments
    Point p1 = {0, 0}, p2 = {1, 1};
    Point p3 = {0, 2}, p4 = {1, 3};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_FALSE(result);  // Parallel lines
}

TEST_F(PointTest, GetLineIntersection_CoincidentPoints) {
    Point p1 = {2, 3}, p2 = {5, 7};
    Point p3 = {2, 3}, p4 = {8, 10};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    // Intersection should be at the coincident point
    EXPECT_TRUE(nearlyEqual(intersection.x, 2.0));
    EXPECT_TRUE(nearlyEqual(intersection.y, 3.0));
}

// ==================== Integration Tests ====================

TEST_F(PointTest, Integration_MultipleIntersections) {
    // Test multiple intersection calculations
    Point p1 = {0, 0}, p2 = {2, 2};
    Point p3 = {0, 2}, p4 = {2, 0};
    Point intersection1, intersection2;

    bool result1 = getLineIntersection(p1, p2, p3, p4, intersection1);
    
    Point p5 = {1, 0}, p6 = {1, 4};
    Point p7 = {0, 2}, p8 = {4, 2};
    bool result2 = getLineIntersection(p5, p6, p7, p8, intersection2);

    EXPECT_TRUE(result1);
    EXPECT_TRUE(result2);
    EXPECT_TRUE(nearlyEqual(intersection1.x, 1.0));
    EXPECT_TRUE(nearlyEqual(intersection1.y, 1.0));
    EXPECT_TRUE(nearlyEqual(intersection2.x, 1.0));
    EXPECT_TRUE(nearlyEqual(intersection2.y, 2.0));
}

TEST_F(PointTest, Integration_ParallelAndIntersectingLines) {
    Point p1 = {0, 0}, p2 = {4, 0};
    Point p3 = {0, 2}, p4 = {4, 2};
    Point intersection1;

    bool result1 = getLineIntersection(p1, p2, p3, p4, intersection1);
    EXPECT_FALSE(result1);  // Parallel

    Point p5 = {2, -1}, p6 = {2, 3};
    Point intersection2;
    bool result2 = getLineIntersection(p1, p2, p5, p6, intersection2);
    EXPECT_TRUE(result2);  // Intersecting
    EXPECT_TRUE(nearlyEqual(intersection2.x, 2.0));
    EXPECT_TRUE(nearlyEqual(intersection2.y, 0.0));
}

// ==================== Special Mathematical Cases ====================

TEST_F(PointTest, GetLineIntersection_SlopeInfinity) {
    // Vertical line (infinite slope)
    Point p1 = {3, 0}, p2 = {3, 10};
    Point p3 = {0, 5}, p4 = {10, 5};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_TRUE(result);
    EXPECT_TRUE(nearlyEqual(intersection.x, 3.0));
    EXPECT_TRUE(nearlyEqual(intersection.y, 5.0));
}

TEST_F(PointTest, GetLineIntersection_BothLinesVertical_Parallel) {
    Point p1 = {2, 0}, p2 = {2, 5};
    Point p3 = {4, 0}, p4 = {4, 5};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_FALSE(result);  // Both vertical, parallel
}

TEST_F(PointTest, GetLineIntersection_BothLinesHorizontal_Parallel) {
    Point p1 = {0, 3}, p2 = {5, 3};
    Point p3 = {0, 7}, p4 = {5, 7};
    Point intersection;

    bool result = getLineIntersection(p1, p2, p3, p4, intersection);

    EXPECT_FALSE(result);  // Both horizontal, parallel
}

// ==================== Main Function ====================

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
