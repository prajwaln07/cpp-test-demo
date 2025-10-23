// Comprehensive Unit Tests for Rectangle.cpp
// Generated for PR #18

#include <gtest/gtest.h>
#include <cmath>

using namespace std;

class Rectangle {
    double x1, y1, x2, y2;
public:
    Rectangle(double _x1, double _y1, double _x2, double _y2);
    double area() const;
    double perimeter() const;
    bool contains(double x, double y) const;
};

class RectangleTest : public ::testing::Test {};

TEST_F(RectangleTest, Area_NormalRectangle) {
    Rectangle rect(0, 0, 4, 3);
    EXPECT_DOUBLE_EQ(rect.area(), 12.0);
}

TEST_F(RectangleTest, Area_Square) {
    Rectangle rect(0, 0, 5, 5);
    EXPECT_DOUBLE_EQ(rect.area(), 25.0);
}

TEST_F(RectangleTest, Area_UnitSquare) {
    Rectangle rect(0, 0, 1, 1);
    EXPECT_DOUBLE_EQ(rect.area(), 1.0);
}

TEST_F(RectangleTest, Area_NegativeCoordinates) {
    Rectangle rect(-2, -3, 2, 3);
    EXPECT_DOUBLE_EQ(rect.area(), 24.0);
}

TEST_F(RectangleTest, Perimeter_NormalRectangle) {
    Rectangle rect(0, 0, 4, 3);
    EXPECT_DOUBLE_EQ(rect.perimeter(), 14.0);
}

TEST_F(RectangleTest, Perimeter_Square) {
    Rectangle rect(0, 0, 5, 5);
    EXPECT_DOUBLE_EQ(rect.perimeter(), 20.0);
}

TEST_F(RectangleTest, Perimeter_LargeRectangle) {
    Rectangle rect(0, 0, 100, 50);
    EXPECT_DOUBLE_EQ(rect.perimeter(), 300.0);
}

TEST_F(RectangleTest, Contains_PointInside) {
    Rectangle rect(0, 0, 10, 10);
    EXPECT_TRUE(rect.contains(5, 5));
    EXPECT_TRUE(rect.contains(1, 1));
    EXPECT_TRUE(rect.contains(9, 9));
}

TEST_F(RectangleTest, Contains_PointOnBoundary) {
    Rectangle rect(0, 0, 10, 10);
    EXPECT_TRUE(rect.contains(0, 0));
    EXPECT_TRUE(rect.contains(10, 10));
    EXPECT_TRUE(rect.contains(0, 5));
    EXPECT_TRUE(rect.contains(5, 0));
}

TEST_F(RectangleTest, Contains_PointOutside) {
    Rectangle rect(0, 0, 10, 10);
    EXPECT_FALSE(rect.contains(-1, 5));
    EXPECT_FALSE(rect.contains(11, 5));
    EXPECT_FALSE(rect.contains(5, -1));
    EXPECT_FALSE(rect.contains(5, 11));
}

TEST_F(RectangleTest, Contains_CornerPoints) {
    Rectangle rect(1, 1, 5, 5);
    EXPECT_TRUE(rect.contains(1, 1));
    EXPECT_TRUE(rect.contains(5, 5));
    EXPECT_TRUE(rect.contains(1, 5));
    EXPECT_TRUE(rect.contains(5, 1));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}