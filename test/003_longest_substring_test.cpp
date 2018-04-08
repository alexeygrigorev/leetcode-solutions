#include "003_longest_substring.h"
#include "gtest/gtest.h"

using namespace std;

LongestSubstringSolution *solution = new LongestSubstringSolution;

TEST(LongestSubstring, Test0) {
    int actual = solution->lengthOfLongestSubstring("abcabcbb");
    EXPECT_EQ(actual, 3);
}

TEST(LongestSubstring, Test1) {
    int actual = solution->lengthOfLongestSubstring("bbbbb");
    EXPECT_EQ(actual, 1);
}

TEST(LongestSubstring, Test2) {
    int actual = solution->lengthOfLongestSubstring("pwwkew");
    EXPECT_EQ(actual, 3);
}

TEST(LongestSubstring, Test3) {
    int actual = solution->lengthOfLongestSubstring("");
    EXPECT_EQ(actual, 0);
}
