#include "008_string_to_integer.h"
#include "gtest/gtest.h"

using namespace std;

StringToIntegerSolution *solution008 = new StringToIntegerSolution;

TEST(StringToInteger, Test0) {
    int actual = solution008->myAtoi("123");
    EXPECT_EQ(actual, 123);
}

TEST(StringToInteger, Test1) {
    int actual = solution008->myAtoi("-123");
    EXPECT_EQ(actual, -123);
}

TEST(StringToInteger, Test2) {
    int actual = solution008->myAtoi("   -42");
    EXPECT_EQ(actual, -42);
}

TEST(StringToInteger, Test3) {
    int actual = solution008->myAtoi("4193 with words");
    EXPECT_EQ(actual, 4193);
}

TEST(StringToInteger, Test4) {
    int actual = solution008->myAtoi("words and 987");
    EXPECT_EQ(actual, 0);
}

TEST(StringToInteger, Test5) {
    int actual = solution008->myAtoi("   -91283472332");
    EXPECT_EQ(actual, -2147483648);
}

TEST(StringToInteger, Test6) {
    int actual = solution008->myAtoi("   +1");
    EXPECT_EQ(actual, 1);
}