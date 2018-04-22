#include "347_top_k_frequent_test.h"
#include "gtest/gtest.h"

using namespace std;

TopKFrequentSolution *solution347 = new TopKFrequentSolution;

TEST(TopKFrequent, Test0) {
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    vector<int> expected = { 1, 2 };
    vector<int> actual = solution347->topKFrequent(nums, k);
    EXPECT_EQ(actual, expected);
}