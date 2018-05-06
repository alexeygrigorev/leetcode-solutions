#include "081_search_in_rotated_sorted_array_2.h"
#include "gtest/gtest.h"

using namespace std;

SearchRotatedSortedArray2Solution *solution081 = new SearchRotatedSortedArray2Solution;

TEST(SearchRotatedSortedArray2, Test0) {
    vector<int> nums = { 2,5,6,0,0,1,2 };
    int target = 0;
    bool result = solution081->search(nums, target);
    EXPECT_TRUE(result);
}

TEST(SearchRotatedSortedArray2, Test1) {
    vector<int> nums = { 2,5,6,0,0,1,2 };
    int target = 3;
    bool result = solution081->search(nums, target);
    EXPECT_FALSE(result);
}


bool contains(vector<int> v, int t) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == t) {
            return true;
        }
    }
    return false;
}

vector<int> shift081(vector<int> nums, int size) {
    vector<int> copy(nums);
    rotate(copy.begin(), copy.begin() + size, copy.end());
    return copy;
}

TEST(SearchRotatedSortedArray2, Test4) {
    vector<int> nums = { 0, 0, 10, 10, 10, 20, 20, 30, 40, 40, 40,
                         50, 50, 50, 60, 70, 70, 70 };
    for (int s = 0; s < 18; s++) {
        vector<int> nums_shifted = shift081(nums, s);
        for (int i = 0; i < nums_shifted.size(); i++) {
            printf("%d, ", nums_shifted[i]);
        }
        printf("\n");
        for (int i = -10; i <= 80; i++) {
            bool expected = contains(nums_shifted, i);
            bool actual = solution081->search(nums_shifted, i);
            printf("target=%d, outcome=%d\n", i, actual == expected);
            EXPECT_EQ(actual, expected);
        }
    }
}

TEST(SearchRotatedSortedArray2, Test5) {
    vector<int> nums = { 10, 10, 10, 20, 20, 30, 40, 40, 40, 50, 50, 50, 60, 70, 70, 70, 0, 0 };
    bool expected = true;
    bool actual = solution081->search(nums, 10);
    EXPECT_EQ(actual, expected);
}

TEST(SearchRotatedSortedArray2, Test6) {
    vector<int> nums = { 10, 10, 10, 20, 20, 30, 40, 40, 40, 50, 50, 50, 60,
                         70, 70, 70, 0, 0 };
    bool expected = true;
    bool actual = solution081->search(nums, 0);
    EXPECT_EQ(actual, expected);
}

TEST(SearchRotatedSortedArray2, Test7) {
    vector<int> nums = { 20, 20, 30, 40, 40, 40, 50, 50, 50, 60, 70, 70, 70,
                         0, 0, 10, 10, 10,};
    bool expected = true;
    bool actual = solution081->search(nums, 0);
    EXPECT_EQ(actual, expected);
}

TEST(SearchRotatedSortedArray2, Test8) {
    vector<int> nums = { 70, 70, 0, 0, 10, 10, 10, 20, 20, 30, 40, 40, 40, 50,
                         50, 50, 60, 70};
    bool expected = true;
    bool actual = solution081->search(nums, 0);
    EXPECT_EQ(actual, expected);
}