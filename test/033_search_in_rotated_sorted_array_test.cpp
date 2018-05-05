#include "033_search_in_rotated_sorted_array.h"
#include "gtest/gtest.h"

using namespace std;

SearchRotatedSortedArraySolution *solution033 = new SearchRotatedSortedArraySolution;

TEST(SearchRotatedSortedArray, Test0) {
    vector<int> nums = { 4,5,6,7,0,1,2 };
    int target = 0;
    int actual = solution033->search(nums, target);
    EXPECT_EQ(actual, 4);
}

TEST(SearchRotatedSortedArray, Test1) {
    vector<int> nums = { 4,5,6,7,0,1,2 };
    int target = 3;
    int actual = solution033->search(nums, target);
    EXPECT_EQ(actual, -1);
}
