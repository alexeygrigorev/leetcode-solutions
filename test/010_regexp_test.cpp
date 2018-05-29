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
