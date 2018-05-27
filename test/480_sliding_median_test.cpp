#include "480_sliding_median.h"
#include "gtest/gtest.h"

using namespace std;

SlidingMedianSolution *solution480 = new SlidingMedianSolution;

TEST(SlidingMedian, Test0) {
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<double> actual = solution480->medianSlidingWindow(input, k);
    vector<double> expected = {1,-1,-1,3,5,6};

    EXPECT_EQ(actual, expected);
}