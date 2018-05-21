#include "295_median.h"
#include "gtest/gtest.h"

using namespace std;

TEST(MedianFinder, Test0) {
    MedianFinderSolution *median = new MedianFinderSolution;
    median->addNum(1);
    EXPECT_EQ(1.0, median->findMedian());
    median->addNum(2);
    EXPECT_EQ(1.5, median->findMedian());
    median->addNum(3);
    EXPECT_EQ(2.0, median->findMedian());
    median->addNum(4);
    EXPECT_EQ(2.5, median->findMedian());
}

TEST(MedianFinder, Test1) {
    MedianFinderSolution *median = new MedianFinderSolution;
    median->addNum(-1);
    EXPECT_EQ(-1.0, median->findMedian());
    median->addNum(-2);
    EXPECT_EQ(-1.5, median->findMedian());
    median->addNum(-3);
    EXPECT_EQ(-2.0, median->findMedian());
    median->addNum(-4);
    EXPECT_EQ(-2.5, median->findMedian());
    median->addNum(-5);
    EXPECT_EQ(-3.0, median->findMedian());
}