#include "215_kth_element.h"
#include "gtest/gtest.h"

using namespace std;

KthLargestSolution *solution215 = new KthLargestSolution;

TEST(KthLargest, Test0) {
    vector<int> nums = {5, 6, 4}; // { 3, 2, 1, 5, 6, 4 };
    int k = 2;
    int actual = solution215->findKthLargest(nums, k);
    EXPECT_EQ(actual, 5);
}

TEST(KthLargest, Test1) {
    vector<int> nums = { 3, 4 };
    int k = 2;
    int actual = solution215->findKthLargest(nums, k);
    EXPECT_EQ(actual, 3);
}

TEST(KthLargest, Test2) {
    vector<int> nums = { 0, 1, 2, 3, 4 };
    int k = 2;
    int actual = solution215->findKthLargest(nums, k);
    EXPECT_EQ(actual, 3);
}

TEST(KthLargest, Test3) {
    vector<int> nums = { 0, 0, 1, 1, 2, 2, 3, 4, 4 };
    int k = 7;
    int actual = solution215->findKthLargest(nums, k);
    EXPECT_EQ(actual, 1);
}

TEST(KthLargest, Test4) {
    vector<int> nums = { 4, 0, 1, 3, 1, 2, 0, 2, 4 };
    int k = 7;
    int actual = solution215->findKthLargest(nums, k);
    EXPECT_EQ(actual, 1);
}

TEST(KthLargest, Test5) {
    vector<int> nums = { 7,6,5,4,3,2,1 };
    int k = 2;
    int actual = solution215->findKthLargest(nums, k);
    EXPECT_EQ(actual, 6);
}