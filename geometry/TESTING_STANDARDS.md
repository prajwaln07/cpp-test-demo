# Geometry Module - Testing Standards

## 📐 Module Overview

This document defines testing standards specific to the `geometry/` module. All geometry-related code involves 2D/3D shapes, coordinate systems, spatial calculations, and geometric algorithms.

---

## 🎯 Core Testing Principles for Geometry

### 1. Coordinate System Testing
- **Origin tests**: Always test with origin (0, 0) or (0, 0, 0)
- **Quadrant coverage**: Test points in all quadrants (positive, negative, mixed coordinates)
- **Axis alignment**: Test shapes aligned with axes and rotated shapes
- **Boundary cases**: Points exactly on boundaries, edges, or vertices

### 2. Floating-Point Precision
- **Use epsilon comparison**: Always use `EXPECT_NEAR` or custom `nearlyEqual()` for floating-point results
- **Default epsilon**: `1e-9` for high precision, `1e-5` for less critical comparisons
- **Test precision limits**: Include tests with very small and very large coordinates

### 3. Geometric Properties
- **Symmetry**: Test symmetric shapes and operations
- **Invariants**: Verify geometric invariants (e.g., area always positive, perimeter always positive)
- **Transformations**: Test scaling, rotation, translation effects
- **Degenerate cases**: Zero-area shapes, collinear points, overlapping shapes

---

## 📋 Required Test Categories

### A. Shape Construction Tests
```cpp
// For classes (Rectangle, Circle, Polygon, etc.)
✅ Constructor with valid parameters
✅ Constructor with zero dimensions
✅ Constructor with negative coordinates
✅ Constructor with equal points (degenerate case)
✅ Constructor with very large/small values
```

### B. Measurement Tests
```cpp
// For area, perimeter, volume, etc.
✅ Zero/unit shapes
✅ Integer coordinate shapes
✅ Fractional coordinate shapes
✅ Very small shapes (precision test)
✅ Very large shapes (overflow prevention)
✅ Degenerate shapes (zero area/perimeter)
```

### C. Spatial Relationship Tests
```cpp
// For containment, intersection, distance, etc.
✅ Point inside shape
✅ Point on boundary
✅ Point outside shape
✅ Point at vertices
✅ Shapes overlapping
✅ Shapes touching (tangent)
✅ Shapes completely separate
✅ One shape inside another
```

### D. Algorithm-Specific Tests
```cpp
// For geometric algorithms
✅ General case
✅ Edge cases (parallel lines, collinear points)
✅ Boundary conditions
✅ Degenerate inputs
✅ Numerical stability
```

---

## 🔍 Geometry-Specific Test Patterns

### Pattern 1: Point/Coordinate Testing
```cpp
TEST_F(GeometryTest, Function_OriginPoint) {
    Point p = {0, 0};
    // Test with origin
}

TEST_F(GeometryTest, Function_AllQuadrants) {
    Point p1 = {5, 5};    // Quadrant 1 (+, +)
    Point p2 = {-5, 5};   // Quadrant 2 (-, +)
    Point p3 = {-5, -5};  // Quadrant 3 (-, -)
    Point p4 = {5, -5};   // Quadrant 4 (+, -)
    // Test in all quadrants
}
```

### Pattern 2: Boundary Testing
```cpp
TEST_F(GeometryTest, Function_PointOnBoundary) {
    // Test points exactly on edges, vertices, circumference
}

TEST_F(GeometryTest, Function_PointJustInside) {
    // Test points slightly inside (epsilon inside)
}

TEST_F(GeometryTest, Function_PointJustOutside) {
    // Test points slightly outside (epsilon outside)
}
```

### Pattern 3: Degenerate Shape Testing
```cpp
TEST_F(GeometryTest, Function_ZeroAreaShape) {
    // Rectangle with same x1=x2 or y1=y2
    // Circle with radius 0
    // Polygon with all points collinear
}

TEST_F(GeometryTest, Function_CollinearPoints) {
    // Three or more points on same line
}
```

### Pattern 4: Precision Testing
```cpp
TEST_F(GeometryTest, Function_SmallValues) {
    // Coordinates like 0.0001, 0.00001
    EXPECT_NEAR(result, expected, 1e-9);
}

TEST_F(GeometryTest, Function_LargeValues) {
    // Coordinates like 10000, 1000000
    EXPECT_NEAR(result, expected, 1e-5);
}
```

---

## 📐 Common Geometry Test Scenarios

### For 2D Shapes (Rectangle, Circle, Polygon, etc.)

#### Must-Have Tests:
1. **Construction**
   - Valid parameters
   - Zero dimensions
   - Negative coordinates
   - Identical points

2. **Area Calculation**
   - Unit shape (1x1, radius=1)
   - Integer dimensions
   - Fractional dimensions
   - Zero area (degenerate)
   - Large dimensions

3. **Perimeter Calculation**
   - Unit shape
   - Integer dimensions
   - Fractional dimensions
   - Zero perimeter (degenerate)

4. **Point Containment**
   - Point inside (clearly)
   - Point outside (clearly)
   - Point on boundary
   - Point at vertices/corners
   - Point very close to boundary (epsilon test)

5. **Boundary Cases**
   - Minimum valid shape
   - Maximum reasonable shape
   - Axis-aligned vs rotated

### For Point/Line Operations

#### Must-Have Tests:
1. **Distance Calculations**
   - Same point (distance = 0)
   - Points on same axis
   - Points in different quadrants
   - Very close points (precision)
   - Very far points

2. **Line Intersection**
   - Intersecting lines
   - Parallel lines (no intersection)
   - Coincident lines (infinite intersections)
   - Perpendicular lines
   - Vertical/horizontal lines
   - Intersection at origin
   - Intersection outside segment bounds

3. **Angle Calculations**
   - 0°, 45°, 90°, 180°, 270°, 360°
   - Acute, obtuse, right angles
   - Reflex angles
   - Negative angles

---

## ✅ Test Checklist for Geometry Functions

Before completing tests for a geometry function, verify:

- [ ] **Origin test**: Tested with (0,0) or origin point
- [ ] **All quadrants**: Covered positive, negative, mixed coordinates
- [ ] **Boundary precision**: Used `EXPECT_NEAR` for floating-point comparisons
- [ ] **Degenerate cases**: Tested zero-area, collinear, overlapping
- [ ] **Edge cases**: Tested parallel lines, tangent shapes, vertices
- [ ] **Precision range**: Tested with very small (0.0001) and large (10000) values
- [ ] **Invariants**: Verified geometric properties (non-negative area, etc.)
- [ ] **Symmetry**: Tested symmetric inputs if applicable
- [ ] **Integration**: Tested relationships between functions

---

## 🧪 Example Test Structure

```cpp
// ==================== [FunctionName] Tests ====================

// Basic Cases
TEST_F(GeometryTest, FunctionName_ValidInput_ReturnsExpected) { }

// Coordinate System Coverage
TEST_F(GeometryTest, FunctionName_AtOrigin) { }
TEST_F(GeometryTest, FunctionName_AllQuadrants) { }
TEST_F(GeometryTest, FunctionName_NegativeCoordinates) { }

// Boundary Cases
TEST_F(GeometryTest, FunctionName_OnBoundary) { }
TEST_F(GeometryTest, FunctionName_AtVertices) { }
TEST_F(GeometryTest, FunctionName_JustInside) { }
TEST_F(GeometryTest, FunctionName_JustOutside) { }

// Degenerate Cases
TEST_F(GeometryTest, FunctionName_ZeroArea) { }
TEST_F(GeometryTest, FunctionName_CollinearPoints) { }
TEST_F(GeometryTest, FunctionName_IdenticalPoints) { }

// Precision Tests
TEST_F(GeometryTest, FunctionName_VerySmallValues) { }
TEST_F(GeometryTest, FunctionName_VeryLargeValues) { }
TEST_F(GeometryTest, FunctionName_FloatingPointPrecision) { }

// Special Cases
TEST_F(GeometryTest, FunctionName_AxisAligned) { }
TEST_F(GeometryTest, FunctionName_Rotated) { }
TEST_F(GeometryTest, FunctionName_Symmetric) { }
```

---

## 🎯 Common Pitfalls to Avoid

### ❌ DON'T:
- Use `EXPECT_EQ` for floating-point comparisons
- Forget to test negative coordinates
- Ignore degenerate cases (zero area, collinear points)
- Test only integer coordinates
- Skip boundary/edge cases
- Assume shapes are axis-aligned

### ✅ DO:
- Use `EXPECT_NEAR` with appropriate epsilon
- Test all coordinate quadrants
- Test degenerate/edge cases explicitly
- Include fractional coordinates
- Test points on boundaries and vertices
- Test both axis-aligned and rotated shapes
- Verify geometric invariants

---

## 📊 Minimum Test Coverage

| Category | Minimum Tests |
|----------|---------------|
| Construction | 5 |
| Area/Volume | 5 |
| Perimeter/Surface Area | 5 |
| Point Containment | 7 |
| Distance/Intersection | 8 |
| Edge/Degenerate Cases | 5 |
| Precision Tests | 3 |
| Integration Tests | 2 |

**Minimum Total: 40+ tests per file**

---

## 🔗 Related Standards

- Global: `STANDARD_PRACTICES.md`
- Config: `TEST_FOLDER_CONFIG.md`
- Tests Location: `tests/geometry/`

---

## 📝 Notes

- Always include a helper function `nearlyEqual(double a, double b, double epsilon = 1e-9)` in test fixtures
- For computational geometry algorithms, add tests for numerical stability
- Document any assumptions about coordinate systems (e.g., origin, axis orientation)
- Consider adding visualization comments for complex geometric scenarios

---

**Module**: Geometry  
**Framework**: Google Test  
**Language**: C++11  
**Last Updated**: October 23, 2025  
**Version**: 1.0
