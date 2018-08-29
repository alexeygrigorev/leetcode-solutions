#include "016_three_sum_closest.h"
#include "gtest/gtest.h"

using namespace std;

ThreeSumClosestSolution *solution016 = new ThreeSumClosestSolution;

TEST(ThreeSumClosest, Test0) {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int actual = solution016->threeSumClosest(nums, target);
    int expected = 2;

    EXPECT_EQ(actual, expected);
}

