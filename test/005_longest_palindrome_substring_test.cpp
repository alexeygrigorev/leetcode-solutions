#include "005_longest_palindrome_substring.h"
#include "gtest/gtest.h"

using namespace std;

LongestPalindromeSubstringSolution *solution005 = new LongestPalindromeSubstringSolution;

TEST(LongestPalindromeSubstring, Test0) {
    int actual = solution005->longestPalindrome("babad");
    EXPECT_EQ(actual, "bab");
}
