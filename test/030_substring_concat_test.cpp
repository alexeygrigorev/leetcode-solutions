#include "030_substring_concat.h"
#include "gtest/gtest.h"

using namespace std;

SubstringConcatSolution *solution030 = new SubstringConcatSolution;

TEST(SubstringConcat, TestSimple) {
    string str = "barfoo";
    vector<string> words = { "foo", "bar" };
    vector<int> actual = solution030->findSubstring(str, words);
    vector<int> expected = { 0 };
    EXPECT_EQ(actual, expected);
}

TEST(SubstringConcat, Test0) {
    string str = "barfoothefoobarman";
    vector<string> words = { "foo", "bar" };
    vector<int> actual = solution030->findSubstring(str, words);
    vector<int> expected = { 0, 9 };
    EXPECT_EQ(actual, expected);
}

TEST(SubstringConcat, Test1) {
    string str = "fooowingdingbarrwing";
    vector<string> words = { "fooo", "barr", "wing", "ding", "wing" };
    vector<int> actual = solution030->findSubstring(str, words);
    vector<int> expected = { 0 };
    EXPECT_EQ(actual, expected);
}

TEST(SubstringConcat, Test11) {
    string str = "_fooowingdingbarrwing_";
    vector<string> words = { "fooo", "barr", "wing", "ding", "wing" };
    vector<int> actual = solution030->findSubstring(str, words);
    vector<int> expected = { 1 };
    EXPECT_EQ(actual, expected);
}

TEST(SubstringConcat, Test12) {
    string str = "fooowingdingbarrwingxxxxxxxxxxxxxxx";
    vector<string> words = { "fooo", "barr", "wing", "ding", "wing" };
    vector<int> actual = solution030->findSubstring(str, words);
    vector<int> expected = { 0 };
    EXPECT_EQ(actual, expected);
}

TEST(SubstringConcat, Test2) {
    string str = "barfofoobarfo";
    vector<string> words = { "foo", "bar", "barfo" };
    vector<int> actual = solution030->findSubstring(str, words);
    vector<int> expected = { 0 };
    EXPECT_EQ(actual, expected);
}

TEST(SubstringConcat, Test3) {
    string str = "barfofoobarfo";
    vector<string> words = { };
    vector<int> actual = solution030->findSubstring(str, words);
    vector<int> expected = { };
    EXPECT_EQ(actual, expected);
}

string repeat_string(string s, int n) {
    stringstream os;

    for (int i = 0; i < n; i++) {
        os << s;
    }

    return os.str();
}

vector<string> repeat_vector(vector<string> strs, int n) {
    vector<string> result;
    for (int i = 0; i < n; i++) {
        for (string s : strs) {
            result.push_back(s);
        }
    }
    return result;
}

TEST(SubstringConcat, Test10) {
    string str = repeat_string("ab", 5000);
    vector<string> words = repeat_vector({"ab", "ba"}, 200);
    vector<int> actual = solution030->findSubstring(str, words);
    vector<int> expected = { };
    EXPECT_EQ(actual, expected);
}