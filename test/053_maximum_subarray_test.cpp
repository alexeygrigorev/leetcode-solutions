#include "053_maximum_subarray.h"
#include "gtest/gtest.h"

using namespace std;

MaximumSubarraySolution *solution053 = new MaximumSubarraySolution;

TEST(MaximumSubarray, Test0) {
    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int actual = solution053->maxSubArray(nums);
    EXPECT_DOUBLE_EQ(actual, 6);
}

TEST(MaximumSubarray, Test1) {
    vector<int> nums = { 1, -6, 2, -5, 3, -4, 4, -3, 5, -2, 6, -1 };
    int actual = solution053->maxSubArray(nums);
    EXPECT_DOUBLE_EQ(actual, 10);
}

TEST(MaximumSubarray, Test2) {
    vector<int> nums = { 6, -6, 1, -2, 6, 3, 1, -1, 2, -6, 6 };
    int actual = solution053->maxSubArray(nums);
    EXPECT_DOUBLE_EQ(actual, 11);
}

TEST(MaximumSubarray, Test3) {
    vector<int> nums = { -1, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6 };
    int actual = solution053->maxSubArray(nums);
    EXPECT_DOUBLE_EQ(actual, 6);
}