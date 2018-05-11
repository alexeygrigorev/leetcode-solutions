#include "200_number_islands.h"
#include "gtest/gtest.h"

using namespace std;

NumberOfIslandsSolution *solution200 = new NumberOfIslandsSolution;

vector<vector<char>> strings_to_chars(vector<string> &input) {
    vector<vector<char>> result;

    for (int i = 0; i < input.size(); i++) {
        string s = input[i];
        vector<char> res;
        for (int j = 0; j < s.size(); j++) {
            res.push_back(s[j]);
        }
        result.push_back(res);
    }

    return result;
}

TEST(NumberOfIslands, Test0) {
    vector<string> strings = {
        "11110",
        "11010",
        "11000",
        "00000"
    };

    vector<vector<char>> grid = strings_to_chars(strings);
    int actual = solution200->numIslands(grid);
    int expected = 1;

    EXPECT_EQ(actual, expected);
}

TEST(NumberOfIslands, Test1) {
    vector<string> strings = {
        "11000",
        "11000",
        "00100",
        "00011"
    };

    vector<vector<char>> grid = strings_to_chars(strings);
    int actual = solution200->numIslands(grid);
    int expected = 3;

    EXPECT_EQ(actual, expected);
}

TEST(NumberOfIslands, Test2) {
    vector<string> strings = {
        "1",
    };

    vector<vector<char>> grid = strings_to_chars(strings);
    int actual = solution200->numIslands(grid);
    int expected = 1;

    EXPECT_EQ(actual, expected);
}

TEST(NumberOfIslands, Test3) {
    vector<string> strings = {
         {"11111011111111101011"},
         {"01111111111110111110"},
         {"10111001101111111111"},
         {"11110111111111111111"},
         {"10011111111111111111"},
         {"10111111011101110111"},
         {"01111111111101101111"},
         {"11111111111101111011"},
         {"11111111110111111111"},
         {"11111111111111111111"},
         {"01111111011111111111"},
         {"11111111111111111111"},
         {"11111111111111111111"},
         {"11111011111110111111"},
         {"10111110111011110111"},
         {"11111111111101111110"},
         {"11111111111110111100"},
         {"11111111111111111111"},
         {"11111111111111111111"},
         {"11111111111111111111"}
    };

    vector<vector<char>> grid = strings_to_chars(strings);
    int actual = solution200->numIslands(grid);
    int expected = 1;

    EXPECT_EQ(actual, expected);
}

TEST(NumberOfIslands, Test4) {
    vector<string> strings = {
        "111",
        "111",
        "111"
    };

    vector<vector<char>> grid = strings_to_chars(strings);
    int actual = solution200->numIslands(grid);
    int expected = 1;

    EXPECT_EQ(actual, expected);
}

TEST(NumberOfIslands, Test5) {
    vector<string> strings = {
        "010",
        "101",
        "010"
    };

    vector<vector<char>> grid = strings_to_chars(strings);
    int actual = solution200->numIslands(grid);
    int expected = 4;

    EXPECT_EQ(actual, expected);
}