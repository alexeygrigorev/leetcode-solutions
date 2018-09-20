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