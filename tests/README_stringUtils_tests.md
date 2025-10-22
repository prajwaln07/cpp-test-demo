# String Utils Test Suite

Comprehensive unit tests for the String Utilities library.

## Test Coverage

This test suite provides **complete coverage** for all 8 string utility functions:

### Functions Tested
- ✅ `reverseString()` - String reversal
- ✅ `isPalindrome()` - Palindrome detection (case-insensitive, ignores special chars)
- ✅ `toUpperCase()` - Convert to uppercase
- ✅ `toLowerCase()` - Convert to lowercase
- ✅ `countVowels()` - Count vowels (case-insensitive)
- ✅ `split()` - Split string by delimiter
- ✅ `trim()` - Remove leading/trailing whitespace
- ✅ `isNumeric()` - Check if string contains only digits

## Test Statistics

- **Total Test Cases:** 60+
- **Test Categories:**
  - Normal/Valid inputs
  - Edge cases (empty strings, single characters)
  - Error conditions (invalid inputs)
  - Integration tests (combining multiple functions)

## Building and Running Tests

### Prerequisites
- C++11 or later
- Google Test framework
- CMake (optional but recommended)

### Option 1: Using g++ directly

```bash
# Compile with Google Test
g++ -std=c++11 -isystem /path/to/googletest/include \
    -pthread stringUtils_test.cpp ../stringUtils.cpp \
    /path/to/googletest/lib/libgtest.a \
    /path/to/googletest/lib/libgtest_main.a \
    -o stringUtils_test

# Run the tests
./stringUtils_test
```

### Option 2: Using CMake (Recommended)

Create a `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)
project(StringUtilsTests)

set(CMAKE_CXX_STANDARD 11)

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(stringUtils_test 
    stringUtils_test.cpp
    ../stringUtils.cpp
)

# Link Google Test
target_link_libraries(stringUtils_test ${GTEST_LIBRARIES} pthread)

# Enable testing
enable_testing()
add_test(NAME StringUtilsTest COMMAND stringUtils_test)
```

Then build:

```bash
mkdir build
cd build
cmake ..
make
./stringUtils_test
```

## Expected Output

When all tests pass, you should see:

```
[==========] Running 60 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 60 tests from StringUtilsTest
[ RUN      ] StringUtilsTest.ReverseString_NormalString
[       OK ] StringUtilsTest.ReverseString_NormalString (0 ms)
...
[----------] 60 tests from StringUtilsTest (X ms total)

[==========] 60 tests from 1 test suite ran. (X ms total)
[  PASSED  ] 60 tests.
```

## Test Examples

### Example 1: Testing reverseString
```cpp
TEST_F(StringUtilsTest, ReverseString_NormalString) {
    EXPECT_EQ(reverseString("hello"), "olleh");
    EXPECT_EQ(reverseString("world"), "dlrow");
}
```

### Example 2: Testing isPalindrome
```cpp
TEST_F(StringUtilsTest, IsPalindrome_ValidPalindromes) {
    EXPECT_TRUE(isPalindrome("madam"));
    EXPECT_TRUE(isPalindrome("A man a plan a canal Panama"));
}
```

### Example 3: Testing edge cases
```cpp
TEST_F(StringUtilsTest, Trim_OnlySpaces) {
    EXPECT_EQ(trim("     "), "");
}
```

## Continuous Integration

These tests can be integrated into your CI/CD pipeline:

```yaml
# Example GitHub Actions workflow
- name: Run C++ Tests
  run: |
    mkdir build && cd build
    cmake ..
    make
    ./stringUtils_test
```

## Contributing

To add more tests:
1. Follow the naming convention: `FunctionName_TestScenario`
2. Use descriptive test names
3. Cover normal, edge, and error cases
4. Add comments for complex test logic

## Related Files

- **Implementation:** `../stringUtils.cpp`
- **Header:** `../stringUtils.h`
- **Original PR:** #16
