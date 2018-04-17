#include "215_kth_element.h"
#include "gtest/gtest.h"

using namespace std;

KthLargestSolution *solution215 = new KthLargestSolution;

TEST(KthLargest, Test0) {
    vector<int> nums = { 3, 2, 1, 5, 6, 4 };
    int k = 2;
    int actual = solution215->findKthLargest(nums, k);
    EXPECT_EQ(actual, 5);
}
