#include "004_median_of_2_sorted_arrays.h"
#include "gtest/gtest.h"

using namespace std;

MedianOfSortedArraysSolution *solution004 = new MedianOfSortedArraysSolution;

TEST(MedianOfSortedArray, Test0) {
    vector<int> v1 = { 1, 3 };
    vector<int> v2 = { 2 };
    double actual = solution004->findMedianSortedArrays(v1, v2);
    EXPECT_DOUBLE_EQ(actual, 2.0);
}

TEST(MedianOfSortedArray, Test1) {
    vector<int> v1 = { 1, 2 };
    vector<int> v2 = { 3, 4 };
    double actual = solution004->findMedianSortedArrays(v1, v2);
    EXPECT_DOUBLE_EQ(actual, 2.5);
}
