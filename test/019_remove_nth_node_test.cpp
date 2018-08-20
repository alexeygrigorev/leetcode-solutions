#include "019_remove_nth_node.h"
#include "gtest/gtest.h"

using namespace std;

RemoveNthNodeFromEndOfListSolution *solution019 = new RemoveNthNodeFromEndOfListSolution;


TEST(RemoveNthNode, Test0) {
    int n = 1;
    vector<int> list = {1, 2, 3};
    vector<int> expected = {1, 2};

    ListNode *head, *result;

    head = from_list(list);
    result = solution019->removeNthFromEnd(head, n);
    vector<int> actual = to_list(result);

    EXPECT_EQ(actual, expected);
}

TEST(RemoveNthNode, Test1) {
    int n = 1;
    vector<int> list = {1};
    vector<int> expected = {};

    ListNode *head, *result;

    head = from_list(list);
    result = solution019->removeNthFromEnd(head, n);
    vector<int> actual = to_list(result);

    EXPECT_EQ(actual, expected);
}

TEST(RemoveNthNode, Test2) {
    int n = 2;
    vector<int> list = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 2, 3, 5};

    ListNode *head, *result;

    head = from_list(list);
    result = solution019->removeNthFromEnd(head, n);
    vector<int> actual = to_list(result);

    EXPECT_EQ(actual, expected);
}

TEST(RemoveNthNode, Test3) {
    int n = 5;
    vector<int> list = {1, 2, 3, 4, 5};
    vector<int> expected = {2, 3, 4, 5};

    ListNode *head, *result;

    head = from_list(list);
    result = solution019->removeNthFromEnd(head, n);
    vector<int> actual = to_list(result);

    EXPECT_EQ(actual, expected);
}