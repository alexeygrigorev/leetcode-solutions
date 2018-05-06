#include "033_search_in_rotated_sorted_array.h"
#include "gtest/gtest.h"

using namespace std;

SearchRotatedSortedArraySolution *solution033 = new SearchRotatedSortedArraySolution;

TEST(SearchRotatedSortedArray, Test0) {
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 0;
    int actual = solution033->search(nums, target);
    EXPECT_EQ(actual, 4);
}

TEST(SearchRotatedSortedArray, Test1) {
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 3;
    int actual = solution033->search(nums, target);
    EXPECT_EQ(actual, -1);
}

TEST(SearchRotatedSortedArray, Test2) {
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2, 3 };
    for (int i = 0; i < nums.size(); i++) {
        int target = nums[i];
        int actual = solution033->search(nums, target);
        EXPECT_EQ(actual, i);
    }
}

TEST(SearchRotatedSortedArray, Test3) {
    vector<int> nums = { 0, 1, 2, 3, 4, 5, 6, 7 };
    for (int i = 0; i < nums.size(); i++) {
        int target = nums[i];
        int actual = solution033->search(nums, target);
        EXPECT_EQ(actual, i);
    }
}

int find(vector<int> v, int t) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == t) {
            return i;
        }
    }
    return -1;
}

vector<int> shift(vector<int> nums, int size) {
    vector<int> copy(nums);
    rotate(copy.begin(), copy.begin() + size, copy.end());
    return copy;
}

TEST(SearchRotatedSortedArray, Test4) {
    vector<int> nums = { 0, 10, 20, 30, 40, 50, 60, 70 };
    for (int s = 0; s < 7; s++) {
        vector<int> nums_shifted = shift(nums, s);
        for (int i = -10; i <= 80; i++) {
            int expected = find(nums_shifted, i);
            int actual = solution033->search(nums_shifted, i);
            EXPECT_EQ(actual, expected);
        }
    }
}

