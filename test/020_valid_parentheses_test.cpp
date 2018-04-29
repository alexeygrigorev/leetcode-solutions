#include "020_valid_parentheses.h"
#include "gtest/gtest.h"

using namespace std;

ValidParenthesesSolution *solution020 = new ValidParenthesesSolution;

TEST(ValidParentheses, Test0) {
    bool result = solution020->isValid("()");
    EXPECT_TRUE(result);
}

TEST(ValidParentheses, Test1) {
    bool result = solution020->isValid("()[]{}");
    EXPECT_TRUE(result);
}

TEST(ValidParentheses, Test2) {
    bool result = solution020->isValid("(]");
    EXPECT_FALSE(result);
}

TEST(ValidParentheses, Test3) {
    bool result = solution020->isValid("([)]");
    EXPECT_FALSE(result);
}

TEST(ValidParentheses, Test4) {
    bool result = solution020->isValid("{[]}");
    EXPECT_TRUE(result);
}

TEST(ValidParentheses, Test5) {
    bool result = solution020->isValid("]");
    EXPECT_FALSE(result);
}

TEST(ValidParentheses, Test6) {
    bool result = solution020->isValid("[");
    EXPECT_FALSE(result);
}