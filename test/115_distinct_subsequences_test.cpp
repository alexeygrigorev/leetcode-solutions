#include "115_distinct_subsequences.h"
#include "gtest/gtest.h"

using namespace std;

DistinctSubsequencesSolution *solution115 = new DistinctSubsequencesSolution;

TEST(DistinctSubsequences, Test0) {
    string s = "rabbbit";
    string t = "rabbit";

    int actual = solution115->numDistinct(s, t);
    int expected = 3;

    EXPECT_EQ(actual, expected);
}

TEST(DistinctSubsequences, Test1) {
    string s = "babgbag";
    string t = "bag";

    int actual = solution115->numDistinct(s, t);
    int expected = 5;

    EXPECT_EQ(actual, expected);
}

TEST(DistinctSubsequences, TestSlow) {
    string s = string() +
            "daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddec" +
            "deedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeade" +
            "cabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddc" +
            "cbdbcdcbceabcacddbbcedebbcaccac";
    string t = "ceadbaa";

    int actual = solution115->numDistinct(s, t);
    int expected = 8556153;

    EXPECT_EQ(actual, expected);
}

TEST(DistinctSubsequences, TestSlow2) {
    string s = string() +
            "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddea" +
            "eebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcd" +
            "ebeecdaaedaacadbdccabddaddacdddc";
    string t = "bcddceeeebecbc";

    int actual = solution115->numDistinct(s, t);
    int expected = 700531452;

    EXPECT_EQ(actual, expected);
}

