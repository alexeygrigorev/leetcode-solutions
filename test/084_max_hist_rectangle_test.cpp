#include "084_max_hist_rectangle.h"
#include "gtest/gtest.h"

using namespace std;

MaxHistRectangleSolution *solution084 = new MaxHistRectangleSolution;

TEST(MaxHistRectangle, Test0) {
    vector<int> heights = { 2,1,5,6,2,3 };
    int actual = solution084->largestRectangleArea(heights);
    int expected = 10;
    EXPECT_EQ(actual, expected);
}

TEST(MaxHistRectangle, Test1) {
    vector<int> heights = { 2,1,5,6,2,3,0,1,2,3,4,5,4,3,2,1,0,3,3,0 };
    int actual = solution084->largestRectangleArea(heights);
    int expected = 15;
    EXPECT_EQ(actual, expected);
}