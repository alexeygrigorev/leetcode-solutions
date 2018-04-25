#include "152_maximum_product_subarray.h"
#include "gtest/gtest.h"

using namespace std;

MaximumProductSubarraySolution *solution152 = new MaximumProductSubarraySolution;

TEST(MaximumProductSubarray, Test0) {
    vector<int> nums = { 2, 3, -2, 4 };
    int actual = solution152->maxProduct(nums);
    EXPECT_DOUBLE_EQ(actual, 6);
}