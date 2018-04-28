#include "152_maximum_product_subarray.h"
#include "gtest/gtest.h"

using namespace std;

MaximumProductSubarraySolution *solution152 = new MaximumProductSubarraySolution;

TEST(MaximumProductSubarray, Test0) {
    vector<int> nums = { 2, 3, -2, 4 };
    int actual = solution152->maxProduct(nums);
    EXPECT_DOUBLE_EQ(actual, 6);
}

TEST(MaximumProductSubarray, Test1) {
    vector<int> nums = { -2, 0, 1 };
    int actual = solution152->maxProduct(nums);
    EXPECT_DOUBLE_EQ(actual, 1);
}

TEST(MaximumProductSubarray, Test2) {
    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int actual = solution152->maxProduct(nums);
    EXPECT_DOUBLE_EQ(actual, 960);
}

TEST(MaximumProductSubarray, Test3) {
    vector<int> nums = { 1, -6, 2, -5, 3, -4, 4, -3, 5, -2, 6, -1 };
    int actual = solution152->maxProduct(nums);
    EXPECT_DOUBLE_EQ(actual, 518400);
}

TEST(MaximumProductSubarray, Test4) {
    vector<int> nums = { 6, -6, 1, -2, -6, 3, 1, -1, 2, -6, 6 };
    int actual = solution152->maxProduct(nums);
    EXPECT_DOUBLE_EQ(actual, 2592);
}

TEST(MaximumProductSubarray, Test5) {
    vector<int> nums = { -1, 1, -1, 2, -2, 3, -3, -4, -4, 5, -5, 6, -6 };
    int actual = solution152->maxProduct(nums);
    EXPECT_DOUBLE_EQ(actual, 518400);
}

TEST(MaximumProductSubarray, Test6) {
    vector<int> nums = { 6, -3, -10, 0, 2 };
    int actual = solution152->maxProduct(nums);
    EXPECT_DOUBLE_EQ(actual, 180);
}

TEST(MaximumProductSubarray, Test7) {
    vector<int> nums = { -1, -3, -10, 0, 60 };
    int actual = solution152->maxProduct(nums);
    EXPECT_DOUBLE_EQ(actual, 60);
}

TEST(MaximumProductSubarray, Test8) {
    vector<int> nums = { -2, -3, 0, -2, -40 };
    int actual = solution152->maxProduct(nums);
    EXPECT_DOUBLE_EQ(actual, 80);
}

TEST(MaximumProductSubarray, Test9) {
    vector<int> nums = { -2 };
    int actual = solution152->maxProduct(nums);
    EXPECT_DOUBLE_EQ(actual, -2);
}
