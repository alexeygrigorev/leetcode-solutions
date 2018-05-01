#include "005_longest_palindrome_substring.h"
#include "gtest/gtest.h"

using namespace std;

LongestPalindromeSubstringSolution *solution005 = new LongestPalindromeSubstringSolution;

TEST(LongestPalindromeSubstring, Test0) {
    string actual = solution005->longestPalindrome("babad");
    EXPECT_EQ(actual, "bab");
}

TEST(LongestPalindromeSubstring, Test1) {
    string actual = solution005->longestPalindrome("cbbd");
    EXPECT_EQ(actual, "bb");
}

TEST(LongestPalindromeSubstring, Test2) {
    string actual = solution005->longestPalindrome("cbbdb");
    EXPECT_EQ(actual, "bdb");
}

TEST(LongestPalindromeSubstring, Test3) {
    string actual = solution005->longestPalindrome("a");
    EXPECT_EQ(actual, "a");
}