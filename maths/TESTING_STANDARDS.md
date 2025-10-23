# Mathematics Module - Testing Standards

## 🔢 Module Overview

This document defines testing standards specific to the `maths/` module. All mathematics code involves numerical algorithms, number theory, combinatorics, statistics, and mathematical operations.

---

## 🎯 Core Testing Principles for Mathematics

### 1. Numerical Range Testing
- **Zero**: Always test with zero as input
- **One**: Test with one (identity element)
- **Positive numbers**: Small, medium, and large positive integers/floats
- **Negative numbers**: Test negative inputs where applicable
- **Edge values**: Test boundary values (min, max representable numbers)

### 2. Mathematical Properties
- **Identity**: Test identity elements (0 for addition, 1 for multiplication)
- **Commutativity**: Test `f(a,b) == f(b,a)` where applicable
- **Associativity**: Test `f(f(a,b),c) == f(a,f(b,c))` where applicable
- **Distributivity**: Test distribution properties
- **Inverse operations**: Test that inverse operations cancel out

### 3. Algorithm Correctness
- **Known values**: Test against well-known mathematical results
- **Edge cases**: Test algorithm limits and special cases
- **Error conditions**: Test invalid inputs and error handling
- **Performance**: Consider overflow, underflow, and precision limits

---

## 📋 Required Test Categories

### A. Basic Operation Tests
```cpp
// For arithmetic, algebra, etc.
✅ Zero operands
✅ One/identity operands
✅ Small positive numbers (1-10)
✅ Larger positive numbers (100-1000)
✅ Negative numbers
✅ Mixed signs
✅ Boundary values
```

### B. Number Theory Tests
```cpp
// For GCD, LCM, primes, factors, etc.
✅ Prime numbers
✅ Composite numbers
✅ Coprime numbers
✅ Perfect squares
✅ Power of primes
✅ Zero and one (special cases)
✅ Negative numbers (where applicable)
```

### C. Combinatorics Tests
```cpp
// For factorial, permutations, combinations, etc.
✅ n = 0 (base case)
✅ n = 1 (base case)
✅ Small values (2-10)
✅ Larger values (15-20)
✅ Edge cases (r > n, r = 0, r = n)
✅ Symmetry properties
```

### D. Statistical Tests
```cpp
// For mean, median, mode, std dev, etc.
✅ Empty dataset
✅ Single element
✅ All same elements
✅ Sorted dataset
✅ Unsorted dataset
✅ Outliers
✅ Even/odd count
```

---

## 🔍 Mathematics-Specific Test Patterns

### Pattern 1: Zero and Identity Testing
```cpp
TEST_F(MathTest, Function_WithZero) {
    // Test with 0 as input
    EXPECT_EQ(function(0), expected_for_zero);
}

TEST_F(MathTest, Function_WithOne) {
    // Test with 1 as identity
    EXPECT_EQ(function(1), expected_for_one);
}
```

### Pattern 2: Sign Testing
```cpp
TEST_F(MathTest, Function_PositiveNumbers) {
    EXPECT_EQ(function(5), expected);
}

TEST_F(MathTest, Function_NegativeNumbers) {
    EXPECT_EQ(function(-5), expected);
}

TEST_F(MathTest, Function_MixedSigns) {
    EXPECT_EQ(function(5, -3), expected);
}
```

### Pattern 3: Property-Based Testing
```cpp
TEST_F(MathTest, Function_Commutative) {
    // f(a,b) = f(b,a)
    EXPECT_EQ(function(3, 5), function(5, 3));
}

TEST_F(MathTest, Function_Associative) {
    // f(f(a,b),c) = f(a,f(b,c))
    EXPECT_EQ(function(function(2,3),4), function(2,function(3,4)));
}

TEST_F(MathTest, Function_Identity) {
    // f(a, identity) = a
    EXPECT_EQ(function(5, 1), 5);
}
```

### Pattern 4: Known Result Testing
```cpp
TEST_F(MathTest, Function_KnownResults) {
    // Test against well-known mathematical facts
    EXPECT_EQ(factorial(5), 120);
    EXPECT_EQ(fibonacci(10), 55);
    EXPECT_TRUE(isPrime(17));
}
```

---

## 🔢 Common Mathematics Test Scenarios

### For Factorial Functions

#### Must-Have Tests:
1. **Base Cases**
   - 0! = 1
   - 1! = 1
   - 2! = 2

2. **Small Values**
   - 3! = 6
   - 4! = 24
   - 5! = 120

3. **Known Values**
   - 10! = 3,628,800
   - 12! = 479,001,600

4. **Growth Verification**
   - n! > (n-1)!
   - n! = n × (n-1)!

### For GCD/LCM Functions

#### Must-Have Tests:
1. **Identical Numbers**
   - gcd(5,5) = 5
   - lcm(5,5) = 5

2. **One with Zero**
   - gcd(n,0) = n
   - gcd(0,n) = n

3. **Coprime Numbers**
   - gcd(7,11) = 1
   - lcm(7,11) = 77

4. **Properties**
   - gcd(a,b) = gcd(b,a) [Commutativity]
   - lcm(a,b) × gcd(a,b) = a × b
   - gcd(a,b) ≤ min(a,b)
   - lcm(a,b) ≥ max(a,b)

5. **Multiples**
   - If b is multiple of a: gcd(a,b) = a
   - If b is multiple of a: lcm(a,b) = b

### For Prime Functions

#### Must-Have Tests:
1. **Invalid/Special Cases**
   - isPrime(0) = false
   - isPrime(1) = false
   - isPrime(-5) = false

2. **First Prime**
   - isPrime(2) = true

3. **Small Primes**
   - 3, 5, 7, 11, 13, 17, 19, 23, 29, 31...

4. **Small Composites**
   - 4, 6, 8, 9, 10, 12, 14, 15...

5. **Perfect Squares**
   - 4, 9, 16, 25, 49, 121... (all composite)

6. **Large Primes**
   - 97 (largest prime < 100)
   - 101, 103, 107...

7. **Special Composites**
   - Powers of primes: 4, 8, 27, 32...
   - Products of primes: 6, 10, 14, 15...

### For Permutation/Combination Functions

#### Must-Have Tests:
1. **Edge Cases**
   - nPr(n, 0) = 1
   - nCr(n, 0) = 1
   - nPr(n, n) = n!
   - nCr(n, n) = 1
   - nPr/nCr(n, r) where r > n = 0

2. **Basic Cases**
   - nPr(5, 2) = 20
   - nCr(5, 2) = 10

3. **Symmetry**
   - nCr(n, r) = nCr(n, n-r)

4. **Relationship**
   - nPr(n, r) = nCr(n, r) × r!
   - nPr(n, r) ≥ nCr(n, r)

5. **Pascal's Triangle Property**
   - nCr(n, r) = nCr(n-1, r-1) + nCr(n-1, r)

---

## ✅ Test Checklist for Mathematics Functions

Before completing tests for a math function, verify:

- [ ] **Zero test**: Tested with 0 as input
- [ ] **Identity test**: Tested with 1 or relevant identity element
- [ ] **Negative numbers**: Tested with negative inputs (if applicable)
- [ ] **Small values**: Tested with small positive integers (1-10)
- [ ] **Large values**: Tested with larger numbers (100-1000+)
- [ ] **Known results**: Verified against well-known mathematical facts
- [ ] **Properties**: Tested mathematical properties (commutativity, symmetry, etc.)
- [ ] **Edge cases**: Tested boundary conditions and special values
- [ ] **Error cases**: Tested invalid inputs (if applicable)
- [ ] **Integration**: Tested relationships with other functions

---

## 🧪 Example Test Structure

```cpp
// ==================== [FunctionName] Tests ====================

// Base Cases
TEST_F(MathTest, FunctionName_Zero_ReturnsExpected) { }
TEST_F(MathTest, FunctionName_One_ReturnsExpected) { }

// Positive Numbers
TEST_F(MathTest, FunctionName_SmallPositive) { }
TEST_F(MathTest, FunctionName_LargePositive) { }

// Negative Numbers (if applicable)
TEST_F(MathTest, FunctionName_Negative) { }

// Known Results
TEST_F(MathTest, FunctionName_KnownValues) { }

// Properties
TEST_F(MathTest, FunctionName_Commutative) { }
TEST_F(MathTest, FunctionName_Associative) { }
TEST_F(MathTest, FunctionName_Identity) { }

// Edge Cases
TEST_F(MathTest, FunctionName_Boundary) { }
TEST_F(MathTest, FunctionName_Overflow) { }

// Special Cases
TEST_F(MathTest, FunctionName_SpecialInput) { }
```

---

## 🎯 Common Pitfalls to Avoid

### ❌ DON'T:
- Forget to test zero and one
- Skip negative number tests
- Ignore overflow/underflow cases
- Test only small numbers
- Forget to verify mathematical properties
- Use floating-point equality for integer operations
- Skip edge cases (r > n, etc.)

### ✅ DO:
- Test zero, one, and identity elements
- Include negative numbers where appropriate
- Test known mathematical results
- Verify properties (commutativity, associativity, etc.)
- Use appropriate data types (long long for large results)
- Test boundary values
- Include integration tests between related functions
- Document mathematical assumptions

---

## 📊 Minimum Test Coverage

| Category | Minimum Tests |
|----------|---------------|
| Base Cases (0, 1) | 2 |
| Small Positive Numbers | 3 |
| Large Positive Numbers | 2 |
| Negative Numbers | 2 |
| Known Results | 3 |
| Property Tests | 3 |
| Edge Cases | 3 |
| Integration Tests | 2 |

**Minimum Total: 20+ tests per function**

---

## 🔬 Special Considerations

### Number Theory Functions
- Test with primes, composites, and coprime numbers
- Verify algorithmic properties (Euclidean algorithm, etc.)
- Test with powers of primes
- Include consecutive numbers

### Combinatorics Functions
- Test factorial growth
- Verify permutation/combination relationships
- Check for overflow with large inputs
- Test Pascal's triangle properties

### Statistical Functions
- Test with empty, single, and multiple elements
- Include sorted and unsorted data
- Test with duplicates and outliers
- Verify against known statistical results

### Algorithmic Functions
- Test time complexity edge cases
- Verify algorithm correctness
- Test numerical stability
- Include worst-case inputs

---

## 📐 Function Relationship Testing

### Common Relationships to Test:
```cpp
// Factorial and Permutations
EXPECT_EQ(nPr(n, r), factorial(n) / factorial(n - r));

// Factorial and Combinations
EXPECT_EQ(nCr(n, r), factorial(n) / (factorial(r) * factorial(n - r)));

// GCD and LCM
EXPECT_EQ(gcd(a, b) * lcm(a, b), a * b);

// Permutations and Combinations
EXPECT_EQ(nPr(n, r), nCr(n, r) * factorial(r));
```

---

## 🔗 Related Standards

- Global: `STANDARD_PRACTICES.md`
- Config: `TEST_FOLDER_CONFIG.md`
- Tests Location: `tests/maths/`

---

## 📝 Notes

- For functions returning large numbers, use `long long` to prevent overflow
- Document any mathematical assumptions or constraints
- Include references to mathematical definitions when helpful
- Consider adding comments explaining non-obvious test values
- For statistical functions, consider using well-known datasets

---

**Module**: Mathematics  
**Framework**: Google Test  
**Language**: C++11  
**Last Updated**: October 23, 2025  
**Version**: 1.0
