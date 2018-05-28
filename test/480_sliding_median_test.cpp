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

TEST(SlidingMedian, Test1) {
    vector<int> input = {1,1,1,1,1,1,1,1};
    int k = 3;

    vector<double> actual = solution480->medianSlidingWindow(input, k);
    vector<double> expected = {1,1,1,1,1,1};

    EXPECT_EQ(actual, expected);
}

TEST(SlidingMedian, Test2) {
    vector<int> input = {1,1,1,1,1,1,1,1};
    int k = 4;

    vector<double> actual = solution480->medianSlidingWindow(input, k);
    vector<double> expected = {1,1,1,1,1};

    EXPECT_EQ(actual, expected);
}

TEST(SlidingMedian, Test3) {
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    int k = 4;

    vector<double> actual = solution480->medianSlidingWindow(input, k);
    vector<double> expected = {0, 1, 1, 4, 5.5};

    EXPECT_EQ(actual, expected);
}

TEST(SlidingMedian, Test4) {
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    int k = 1;

    vector<double> actual = solution480->medianSlidingWindow(input, k);
    vector<double> expected = {1,3,-1,-3,5,3,6,7};

    EXPECT_EQ(actual, expected);
}

TEST(SlidingMedian, Test5) {
    vector<int> input = {1,2,3,4,2,3,1,4,2};
    int k = 3;

    vector<double> actual = solution480->medianSlidingWindow(input, k);
    vector<double> expected = {2,3,3,3,2,3,2};

    EXPECT_EQ(actual, expected);
}