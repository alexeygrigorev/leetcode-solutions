#include "001_two_sum.h"
#include "gtest/gtest.h"

using namespace std;

TwoSumSolution *solution001 = new TwoSumSolution;

TEST(TwoSum, Test0) {
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> actual = solution001->twoSum(nums, target);
    vector<int> expected = { 0, 1 };
    EXPECT_EQ(expected, actual);
}

TEST(TwoSum, Test1) {
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 22;
    vector<int> actual = solution001->twoSum(nums, target);
    vector<int> expected = { 1, 3 };
    EXPECT_EQ(expected, actual);
}

TEST(TwoSum, Test2) {
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 17;
    vector<int> actual = solution001->twoSum(nums, target);
    vector<int> expected = { 0, 3 };
    EXPECT_EQ(expected, actual);
}
