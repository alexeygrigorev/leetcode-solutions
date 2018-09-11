#include "030_substring_concat.h"
#include "gtest/gtest.h"

using namespace std;

SubstringConcatSolution *solution030 = new SubstringConcatSolution;

TEST(SubstringConcat, Test0) {
    string str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = { "fooo", "barr", "wing", "ding", "wing" };
    vector<int> actual = solution030->findSubstring(str, words);
    vector<int> expected = { 13 };
    EXPECT_EQ(actual, expected);
}
