#include "032_longest_valid_parentheses.h"
#include "gtest/gtest.h"

using namespace std;

LongestValidParenthesesSolution *solution032 = new LongestValidParenthesesSolution;

TEST(LongestValidParentheses, Test0) {
    int actual = solution032->longestValidParentheses("(()");
    EXPECT_EQ(actual, 2);
}

TEST(LongestValidParentheses, Test1) {
    int actual = solution032->longestValidParentheses(")()())");
    EXPECT_EQ(actual, 4);
}

TEST(LongestValidParentheses, Test2) {
    int actual = solution032->longestValidParentheses("))))(()(())()))(()())(");
    EXPECT_EQ(actual, 10);
}

TEST(LongestValidParentheses, Test3) {
    int actual = solution032->longestValidParentheses(")()()()())(()()))()");
    EXPECT_EQ(actual, 8);
}
