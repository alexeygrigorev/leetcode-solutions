#include "148_sort_list.h"
#include "gtest/gtest.h"

using namespace std;

SortListSolution *solution148 = new SortListSolution;

TEST(SortList, FindMiddleTest0) {
    vector<int> nums = { 4, 2, 1, 3, 5, 6};
    ListNode *list = from_list(nums);
    ListNode *middle = solution148->find_middle(list);

    vector<int> actual_head = to_list(list);
    vector<int> expected_head = {4, 2, 1};

    vector<int> actual_middle = to_list(middle);
    vector<int> expected_middle = {3, 5, 6};

    EXPECT_EQ(actual_head, expected_head);
    EXPECT_EQ(actual_middle, expected_middle);
}


TEST(SortList, Test0) {
    vector<int> nums = { 4, 2, 1, 3};
    ListNode *list = from_list(nums);
    ListNode *result = solution148->sortList(list);

    vector<int> actual = to_list(result);
    vector<int> expected = {1, 2, 3, 4};

    EXPECT_EQ(actual, expected);
}

TEST(SortList, Test1) {
    vector<int> nums = {};
    ListNode *list = from_list(nums);
    ListNode *result = solution148->sortList(list);

    vector<int> actual = to_list(result);
    vector<int> expected = {};

    EXPECT_EQ(actual, expected);
}

TEST(SortList, Test2) {
    vector<int> nums = { 2 };
    ListNode *list = from_list(nums);
    ListNode *result = solution148->sortList(list);

    vector<int> actual = to_list(result);
    vector<int> expected = { 2 };

    EXPECT_EQ(actual, expected);
}

TEST(SortList, Test3) {
    vector<int> nums = { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 };
    ListNode *list = from_list(nums);
    ListNode *result = solution148->sortList(list);

    vector<int> actual = to_list(result);
    vector<int> expected = { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 };

    EXPECT_EQ(actual, expected);
}
