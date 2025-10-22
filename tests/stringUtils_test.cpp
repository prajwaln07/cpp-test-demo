// Comprehensive Unit Tests for stringUtils.cpp
// Generated for PR #16
// Framework: Google Test
// Coverage: All string utility functions with edge cases

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

// Function declarations from stringUtils.cpp
string reverseString(const string& str);
bool isPalindrome(const string& str);
string toUpperCase(const string& str);
string toLowerCase(const string& str);
int countVowels(const string& str);
vector<string> split(const string& str, char delimiter);
string trim(const string& str);
bool isNumeric(const string& str);

// Test fixture for string utilities
class StringUtilsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
    
    void TearDown() override {
        // Cleanup code if needed
    }
};

// ============================================================================
// Tests for reverseString
// ============================================================================

TEST_F(StringUtilsTest, ReverseString_NormalString) {
    EXPECT_EQ(reverseString("hello"), "olleh");
    EXPECT_EQ(reverseString("world"), "dlrow");
    EXPECT_EQ(reverseString("C++"), "++C");
}

TEST_F(StringUtilsTest, ReverseString_SingleCharacter) {
    EXPECT_EQ(reverseString("a"), "a");
    EXPECT_EQ(reverseString("Z"), "Z");
}

TEST_F(StringUtilsTest, ReverseString_EmptyString) {
    EXPECT_EQ(reverseString(""), "");
}

TEST_F(StringUtilsTest, ReverseString_WithSpaces) {
    EXPECT_EQ(reverseString("Hello World"), "dlroW olleH");
    EXPECT_EQ(reverseString("  spaces  "), "  secaps  ");
}

TEST_F(StringUtilsTest, ReverseString_Palindrome) {
    EXPECT_EQ(reverseString("madam"), "madam");
    EXPECT_EQ(reverseString("racecar"), "racecar");
}

// ============================================================================
// Tests for isPalindrome
// ============================================================================

TEST_F(StringUtilsTest, IsPalindrome_ValidPalindromes) {
    EXPECT_TRUE(isPalindrome("madam"));
    EXPECT_TRUE(isPalindrome("racecar"));
    EXPECT_TRUE(isPalindrome("A man a plan a canal Panama"));
    EXPECT_TRUE(isPalindrome("Was it a car or a cat I saw"));
}

TEST_F(StringUtilsTest, IsPalindrome_NotPalindromes) {
    EXPECT_FALSE(isPalindrome("hello"));
    EXPECT_FALSE(isPalindrome("world"));
    EXPECT_FALSE(isPalindrome("testing"));
}

TEST_F(StringUtilsTest, IsPalindrome_SingleCharacter) {
    EXPECT_TRUE(isPalindrome("a"));
    EXPECT_TRUE(isPalindrome("Z"));
}

TEST_F(StringUtilsTest, IsPalindrome_EmptyString) {
    EXPECT_TRUE(isPalindrome(""));
}

TEST_F(StringUtilsTest, IsPalindrome_WithSpecialCharacters) {
    EXPECT_TRUE(isPalindrome("A man, a plan, a canal: Panama!"));
    EXPECT_TRUE(isPalindrome("race-car"));
}

TEST_F(StringUtilsTest, IsPalindrome_CaseInsensitive) {
    EXPECT_TRUE(isPalindrome("MaDaM"));
    EXPECT_TRUE(isPalindrome("RaceCar"));
}

// ============================================================================
// Tests for toUpperCase
// ============================================================================

TEST_F(StringUtilsTest, ToUpperCase_LowercaseString) {
    EXPECT_EQ(toUpperCase("hello"), "HELLO");
    EXPECT_EQ(toUpperCase("world"), "WORLD");
}

TEST_F(StringUtilsTest, ToUpperCase_MixedCase) {
    EXPECT_EQ(toUpperCase("HeLLo WoRLd"), "HELLO WORLD");
    EXPECT_EQ(toUpperCase("C++ Programming"), "C++ PROGRAMMING");
}

TEST_F(StringUtilsTest, ToUpperCase_AlreadyUppercase) {
    EXPECT_EQ(toUpperCase("HELLO"), "HELLO");
}

TEST_F(StringUtilsTest, ToUpperCase_EmptyString) {
    EXPECT_EQ(toUpperCase(""), "");
}

TEST_F(StringUtilsTest, ToUpperCase_WithNumbers) {
    EXPECT_EQ(toUpperCase("test123"), "TEST123");
}

TEST_F(StringUtilsTest, ToUpperCase_SpecialCharacters) {
    EXPECT_EQ(toUpperCase("hello!@#world"), "HELLO!@#WORLD");
}

// ============================================================================
// Tests for toLowerCase
// ============================================================================

TEST_F(StringUtilsTest, ToLowerCase_UppercaseString) {
    EXPECT_EQ(toLowerCase("HELLO"), "hello");
    EXPECT_EQ(toLowerCase("WORLD"), "world");
}

TEST_F(StringUtilsTest, ToLowerCase_MixedCase) {
    EXPECT_EQ(toLowerCase("HeLLo WoRLd"), "hello world");
    EXPECT_EQ(toLowerCase("C++ Programming"), "c++ programming");
}

TEST_F(StringUtilsTest, ToLowerCase_AlreadyLowercase) {
    EXPECT_EQ(toLowerCase("hello"), "hello");
}

TEST_F(StringUtilsTest, ToLowerCase_EmptyString) {
    EXPECT_EQ(toLowerCase(""), "");
}

TEST_F(StringUtilsTest, ToLowerCase_WithNumbers) {
    EXPECT_EQ(toLowerCase("TEST123"), "test123");
}

// ============================================================================
// Tests for countVowels
// ============================================================================

TEST_F(StringUtilsTest, CountVowels_NormalString) {
    EXPECT_EQ(countVowels("hello"), 2);  // e, o
    EXPECT_EQ(countVowels("world"), 1);  // o
    EXPECT_EQ(countVowels("aeiou"), 5);  // all vowels
}

TEST_F(StringUtilsTest, CountVowels_NoVowels) {
    EXPECT_EQ(countVowels("bcdfg"), 0);
    EXPECT_EQ(countVowels("xyz"), 0);
}

TEST_F(StringUtilsTest, CountVowels_AllVowels) {
    EXPECT_EQ(countVowels("aaa"), 3);
    EXPECT_EQ(countVowels("AEIOU"), 5);
}

TEST_F(StringUtilsTest, CountVowels_MixedCase) {
    EXPECT_EQ(countVowels("HeLLo"), 2);
    EXPECT_EQ(countVowels("AeIoU"), 5);
}

TEST_F(StringUtilsTest, CountVowels_EmptyString) {
    EXPECT_EQ(countVowels(""), 0);
}

TEST_F(StringUtilsTest, CountVowels_WithSpaces) {
    EXPECT_EQ(countVowels("Hello World"), 3);  // e, o, o
}

// ============================================================================
// Tests for split
// ============================================================================

TEST_F(StringUtilsTest, Split_BySpace) {
    vector<string> result = split("Hello World Test", ' ');
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "Hello");
    EXPECT_EQ(result[1], "World");
    EXPECT_EQ(result[2], "Test");
}

TEST_F(StringUtilsTest, Split_ByComma) {
    vector<string> result = split("apple,banana,cherry", ',');
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "apple");
    EXPECT_EQ(result[1], "banana");
    EXPECT_EQ(result[2], "cherry");
}

TEST_F(StringUtilsTest, Split_EmptyString) {
    vector<string> result = split("", ',');
    EXPECT_TRUE(result.empty());
}

TEST_F(StringUtilsTest, Split_NoDelimiter) {
    vector<string> result = split("HelloWorld", ',');
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "HelloWorld");
}

TEST_F(StringUtilsTest, Split_MultipleConsecutiveDelimiters) {
    vector<string> result = split("a,,b,,c", ',');
    // Empty tokens are filtered out
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "a");
    EXPECT_EQ(result[1], "b");
    EXPECT_EQ(result[2], "c");
}

TEST_F(StringUtilsTest, Split_SingleWord) {
    vector<string> result = split("single", ' ');
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "single");
}

// ============================================================================
// Tests for trim
// ============================================================================

TEST_F(StringUtilsTest, Trim_LeadingSpaces) {
    EXPECT_EQ(trim("   hello"), "hello");
}

TEST_F(StringUtilsTest, Trim_TrailingSpaces) {
    EXPECT_EQ(trim("hello   "), "hello");
}

TEST_F(StringUtilsTest, Trim_BothSides) {
    EXPECT_EQ(trim("   hello   "), "hello");
    EXPECT_EQ(trim("  Madam  "), "Madam");
}

TEST_F(StringUtilsTest, Trim_NoSpaces) {
    EXPECT_EQ(trim("hello"), "hello");
}

TEST_F(StringUtilsTest, Trim_EmptyString) {
    EXPECT_EQ(trim(""), "");
}

TEST_F(StringUtilsTest, Trim_OnlySpaces) {
    EXPECT_EQ(trim("     "), "");
    EXPECT_EQ(trim("   "), "");
}

TEST_F(StringUtilsTest, Trim_InternalSpaces) {
    EXPECT_EQ(trim("  hello world  "), "hello world");
}

TEST_F(StringUtilsTest, Trim_TabsAndNewlines) {
    EXPECT_EQ(trim("\t\nhello\t\n"), "hello");
}

// ============================================================================
// Tests for isNumeric
// ============================================================================

TEST_F(StringUtilsTest, IsNumeric_ValidNumbers) {
    EXPECT_TRUE(isNumeric("12345"));
    EXPECT_TRUE(isNumeric("0"));
    EXPECT_TRUE(isNumeric("999999"));
}

TEST_F(StringUtilsTest, IsNumeric_InvalidNumbers) {
    EXPECT_FALSE(isNumeric("123abc"));
    EXPECT_FALSE(isNumeric("abc123"));
    EXPECT_FALSE(isNumeric("12.34"));
}

TEST_F(StringUtilsTest, IsNumeric_EmptyString) {
    EXPECT_FALSE(isNumeric(""));
}

TEST_F(StringUtilsTest, IsNumeric_WithSpaces) {
    EXPECT_FALSE(isNumeric("123 456"));
    EXPECT_FALSE(isNumeric(" 123"));
}

TEST_F(StringUtilsTest, IsNumeric_NegativeNumber) {
    EXPECT_FALSE(isNumeric("-123"));
}

TEST_F(StringUtilsTest, IsNumeric_SpecialCharacters) {
    EXPECT_FALSE(isNumeric("123!"));
    EXPECT_FALSE(isNumeric("@123"));
}

// ============================================================================
// Integration Tests - Multiple functions together
// ============================================================================

TEST_F(StringUtilsTest, Integration_TrimAndReverse) {
    string input = "  hello  ";
    string trimmed = trim(input);
    string reversed = reverseString(trimmed);
    EXPECT_EQ(reversed, "olleh");
}

TEST_F(StringUtilsTest, Integration_UpperCaseAndCountVowels) {
    string input = "hello world";
    string upper = toUpperCase(input);
    EXPECT_EQ(upper, "HELLO WORLD");
    EXPECT_EQ(countVowels(upper), 3);
}

TEST_F(StringUtilsTest, Integration_SplitAndTrim) {
    string input = " apple , banana , cherry ";
    vector<string> parts = split(input, ',');
    ASSERT_EQ(parts.size(), 3);
    EXPECT_EQ(trim(parts[0]), "apple");
    EXPECT_EQ(trim(parts[1]), "banana");
    EXPECT_EQ(trim(parts[2]), "cherry");
}

// Main test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
