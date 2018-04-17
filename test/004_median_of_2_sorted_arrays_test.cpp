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

TEST(MedianOfSortedArray, Test3) {
    vector<int> v1 = { 1, 2, 4, 5 };
    vector<int> v2 = { 0, 2, 3, 5, 7 };
    double actual = solution004->findMedianSortedArrays(v1, v2);
    EXPECT_DOUBLE_EQ(actual, 3);
}

TEST(MedianOfSortedArray, Test4) {
    vector<int> v2 = { 1, 2, 4, 5 };
    vector<int> v1 = { 0, 2, 3, 5, 7 };
    double actual = solution004->findMedianSortedArrays(v1, v2);
    EXPECT_DOUBLE_EQ(actual, 3);
}

TEST(MedianOfSortedArray, Test5) {
    vector<int> v1 = { 1 };
    vector<int> v2 = { };
    double actual = solution004->findMedianSortedArrays(v1, v2);
    EXPECT_DOUBLE_EQ(actual, 1);
}

TEST(MedianOfSortedArray, Test6) {
    vector<int> v2 = { 1 };
    vector<int> v1 = { };
    double actual = solution004->findMedianSortedArrays(v1, v2);
    EXPECT_DOUBLE_EQ(actual, 1);
}


TEST(MedianOfSortedArray, Test7) {
    vector<int> v1 = { 1, 2 };
    vector<int> v2 = { };
    double actual = solution004->findMedianSortedArrays(v1, v2);
    EXPECT_DOUBLE_EQ(actual, 1.5);
}