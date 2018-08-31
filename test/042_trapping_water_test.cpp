#include "042_trapping_water.h"
#include "gtest/gtest.h"

using namespace std;

TrappingWaterSolution *solution042 = new TrappingWaterSolution;

TEST(TrappingWater, Test0) {
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    int actual = solution042->trap(height);
    EXPECT_EQ(actual, 6);
}

TEST(TrappingWater, Test1) {
    vector<int> height = { 2, 0, 2 };
    int actual = solution042->trap(height);
    EXPECT_EQ(actual, 2);
}

TEST(TrappingWater, Test2) {
    vector<int> height = { 0, 1, 2, 0, 2, 1, 0 };
    int actual = solution042->trap(height);
    EXPECT_EQ(actual, 2);
}

TEST(TrappingWater, Test4) {
    vector<int> height = { 4, 3, 2, 1, 2, 3, 4 };
    int actual = solution042->trap(height);
    EXPECT_EQ(actual, 9);
}

TEST(TrappingWater, Test5) {
    vector<int> height = { 0, 1, 2, 1, 0, 1, 2, 1, 0, 1, 2, 1, 0 };
    int actual = solution042->trap(height);
    EXPECT_EQ(actual, 8);
}

TEST(TrappingWater, Test6) {
    vector<int> height = { 0, 0, 0, 10, 0, 0, 0 };
    int actual = solution042->trap(height);
    EXPECT_EQ(actual, 0);
}

TEST(TrappingWater, Test7) {
    vector<int> height = { 0, 0, 0, 10, 10, 10, 0, 0, 0 };
    int actual = solution042->trap(height);
    EXPECT_EQ(actual, 0);
}

TEST(TrappingWater, Test8) {
    vector<int> height = { 10 };
    int actual = solution042->trap(height);
    EXPECT_EQ(actual, 0);
}

TEST(TrappingWater, Test9) {
    vector<int> height = { 10, 10, 10, 10 };
    int actual = solution042->trap(height);
    EXPECT_EQ(actual, 0);
}
