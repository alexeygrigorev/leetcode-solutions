#include "010_regexp.h"
#include "gtest/gtest.h"

using namespace std;

RegexpSolution *solution010 = new RegexpSolution;

TEST(Regexp, Test0) {
    string s = "aa";
    string p = "a";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, false);
}

TEST(Regexp, Test1) {
    string s = "aa";
    string p = "a*";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, true);
}

TEST(Regexp, Test2) {
    string s = "aa";
    string p = ".*";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, true);
}

TEST(Regexp, Test3) {
    string s = "aab";
    string p = "c*a*b";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, true);
}

TEST(Regexp, Test4) {
    string s = "mississippi";
    string p = "mis*is*p*.";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, false);
}

TEST(Regexp, Test5) {
    string s = "aaa";
    string p = "a*a";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, true);
}

TEST(Regexp, Test6) {
    string s = "mississippi";
    string p = "mis*is*ip*.";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, true);
}

TEST(Regexp, Test7) {
    string s = "";
    string p = ".";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, false);
}

TEST(Regexp, Test8) {
    string s = "a";
    string p = "ab*";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, true);
}

TEST(Regexp, Test9) {
    string s = "bbbba";
    string p = ".*a*a";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, true);
}

TEST(Regexp, Test10) {
    string s = "a";
    string p = "a*a";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, true);
}

TEST(Regexp, Test11) {
    string s = "aaaaaaaaaaaaab";
    string p = "a*a*a*a*a*a*a*a*a*a*c";
    bool actual = solution010->isMatch(s, p);
    EXPECT_EQ(actual, false);
}

TEST(Regexp, SimplifyTest1) {
    string input = "a*a*a*a*a*a*a*a*a*a*c";
    string expected = "a*c";
    string actual = solution010->simplify(input);
    EXPECT_EQ(actual, expected);
}