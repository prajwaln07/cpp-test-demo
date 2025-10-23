// Comprehensive Unit Tests for Armstrong.cpp
// Generated for PR #18

#include <gtest/gtest.h>

using namespace std;

bool isArmstrong(int n);

class ArmstrongTest : public ::testing::Test {};

TEST_F(ArmstrongTest, Armstrong_SingleDigit) {
    // All single-digit numbers are Armstrong numbers
    EXPECT_TRUE(isArmstrong(0));
    EXPECT_TRUE(isArmstrong(1));
    EXPECT_TRUE(isArmstrong(5));
    EXPECT_TRUE(isArmstrong(9));
}

TEST_F(ArmstrongTest, Armstrong_ThreeDigit) {
    EXPECT_TRUE(isArmstrong(153));  // 1^3 + 5^3 + 3^3 = 153
    EXPECT_TRUE(isArmstrong(370));  // 3^3 + 7^3 + 0^3 = 370
    EXPECT_TRUE(isArmstrong(371));  // 3^3 + 7^3 + 1^3 = 371
    EXPECT_TRUE(isArmstrong(407));  // 4^3 + 0^3 + 7^3 = 407
}

TEST_F(ArmstrongTest, Armstrong_NotArmstrong) {
    EXPECT_FALSE(isArmstrong(10));
    EXPECT_FALSE(isArmstrong(100));
    EXPECT_FALSE(isArmstrong(152));
    EXPECT_FALSE(isArmstrong(200));
}

TEST_F(ArmstrongTest, Armstrong_FourDigit) {
    EXPECT_TRUE(isArmstrong(1634));  // 1^4 + 6^4 + 3^4 + 4^4 = 1634
    EXPECT_TRUE(isArmstrong(8208));  // 8^4 + 2^4 + 0^4 + 8^4 = 8208
    EXPECT_TRUE(isArmstrong(9474));  // 9^4 + 4^4 + 7^4 + 4^4 = 9474
}

TEST_F(ArmstrongTest, Armstrong_TwoDigit) {
    EXPECT_FALSE(isArmstrong(10));
    EXPECT_FALSE(isArmstrong(99));
    EXPECT_FALSE(isArmstrong(50));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}