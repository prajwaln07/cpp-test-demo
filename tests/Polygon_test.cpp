// Comprehensive Unit Tests for Polygon.cpp
// Generated for PR #18

#include <gtest/gtest.h>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double polygonPerimeter(const vector<Point>& pts);
double polygonArea(const vector<Point>& pts);
bool isValidPolygon(const vector<Point>& pts);

class PolygonTest : public ::testing::Test {};

// ============================================================================
// Tests for isValidPolygon()
// ============================================================================

TEST_F(PolygonTest, IsValidPolygon_ValidCases) {
    vector<Point> triangle = {{0,0}, {1,0}, {0,1}};
    EXPECT_TRUE(isValidPolygon(triangle));
    
    vector<Point> square = {{0,0}, {1,0}, {1,1}, {0,1}};
    EXPECT_TRUE(isValidPolygon(square));
}

TEST_F(PolygonTest, IsValidPolygon_InvalidCases) {
    vector<Point> empty;
    EXPECT_FALSE(isValidPolygon(empty));
    
    vector<Point> one = {{0,0}};
    EXPECT_FALSE(isValidPolygon(one));
    
    vector<Point> two = {{0,0}, {1,1}};
    EXPECT_FALSE(isValidPolygon(two));
}

// ============================================================================
// Tests for polygonPerimeter()
// ============================================================================

TEST_F(PolygonTest, Perimeter_Triangle) {
    vector<Point> triangle = {{0,0}, {3,0}, {0,4}};
    double expected = 3 + 4 + 5;  // 3-4-5 right triangle
    EXPECT_DOUBLE_EQ(polygonPerimeter(triangle), expected);
}

TEST_F(PolygonTest, Perimeter_Square) {
    vector<Point> square = {{0,0}, {1,0}, {1,1}, {0,1}};
    EXPECT_DOUBLE_EQ(polygonPerimeter(square), 4.0);
}

TEST_F(PolygonTest, Perimeter_EquilateralTriangle) {
    vector<Point> triangle = {{0,0}, {1,0}, {0.5, sqrt(3)/2}};
    EXPECT_NEAR(polygonPerimeter(triangle), 3.0, 0.0001);
}

TEST_F(PolygonTest, Perimeter_Rectangle) {
    vector<Point> rect = {{0,0}, {5,0}, {5,3}, {0,3}};
    EXPECT_DOUBLE_EQ(polygonPerimeter(rect), 16.0);
}

// ============================================================================
// Tests for polygonArea()
// ============================================================================

TEST_F(PolygonTest, Area_Triangle) {
    vector<Point> triangle = {{0,0}, {4,0}, {0,3}};
    EXPECT_DOUBLE_EQ(polygonArea(triangle), 6.0);  // (4*3)/2
}

TEST_F(PolygonTest, Area_Square) {
    vector<Point> square = {{0,0}, {2,0}, {2,2}, {0,2}};
    EXPECT_DOUBLE_EQ(polygonArea(square), 4.0);
}

TEST_F(PolygonTest, Area_Rectangle) {
    vector<Point> rect = {{0,0}, {5,0}, {5,3}, {0,3}};
    EXPECT_DOUBLE_EQ(polygonArea(rect), 15.0);
}

TEST_F(PolygonTest, Area_Pentagon) {
    // Regular pentagon inscribed in unit circle
    vector<Point> pentagon;
    for (int i = 0; i < 5; i++) {
        double angle = 2 * M_PI * i / 5;
        pentagon.push_back({cos(angle), sin(angle)});
    }
    EXPECT_NEAR(polygonArea(pentagon), 2.377, 0.01);
}

TEST_F(PolygonTest, Area_UnitSquare) {
    vector<Point> square = {{0,0}, {1,0}, {1,1}, {0,1}};
    EXPECT_DOUBLE_EQ(polygonArea(square), 1.0);
}

TEST_F(PolygonTest, Area_OrderIndependent) {
    // Clockwise
    vector<Point> cw = {{0,0}, {1,0}, {1,1}, {0,1}};
    // Counter-clockwise
    vector<Point> ccw = {{0,0}, {0,1}, {1,1}, {1,0}};
    
    EXPECT_DOUBLE_EQ(polygonArea(cw), polygonArea(ccw));
}

// ============================================================================
// Integration Tests
// ============================================================================

TEST_F(PolygonTest, Integration_TriangleProperties) {
    vector<Point> triangle = {{0,0}, {3,0}, {0,4}};
    
    EXPECT_TRUE(isValidPolygon(triangle));
    EXPECT_DOUBLE_EQ(polygonPerimeter(triangle), 12.0);
    EXPECT_DOUBLE_EQ(polygonArea(triangle), 6.0);
}

TEST_F(PolygonTest, Integration_SquareProperties) {
    vector<Point> square = {{0,0}, {5,0}, {5,5}, {0,5}};
    
    EXPECT_TRUE(isValidPolygon(square));
    EXPECT_DOUBLE_EQ(polygonPerimeter(square), 20.0);
    EXPECT_DOUBLE_EQ(polygonArea(square), 25.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}