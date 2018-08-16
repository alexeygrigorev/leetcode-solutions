#include "019_remove_nth_node.h"
#include "gtest/gtest.h"

using namespace std;

RemoveNthNodeFromEndOfListSolution *solution019 = new RemoveNthNodeFromEndOfListSolution;


RemoveNthNodeFromEndOfListSolution::ListNode *from_list(vector<int> &list) {
    if (list.empty()) {
        return nullptr;
    }

    RemoveNthNodeFromEndOfListSolution::ListNode *head, *prev, *next;

    head = new RemoveNthNodeFromEndOfListSolution::ListNode;
    head->val = list[0];
    head->next = nullptr;
    prev = head;

    for (int i = 1; i < list.size(); i++) {
        next = new RemoveNthNodeFromEndOfListSolution::ListNode;
        next->val = list[i];
        next->next = nullptr;

        prev->next = next;
        prev = next;
    }

    return head;
}

vector<int> to_list(RemoveNthNodeFromEndOfListSolution::ListNode *head) {
    vector<int> result;

    RemoveNthNodeFromEndOfListSolution::ListNode *node = head;

    while (node != nullptr) {
        result.push_back(node->val);
        node = node->next;
    }

    return result;
}

TEST(RemoveNthNode, TestFromTo) {
    vector<int> list = {1, 2, 3};
    RemoveNthNodeFromEndOfListSolution::ListNode *head = from_list(list);
    vector<int> result = to_list(head);
    EXPECT_EQ(result, list);
}

TEST(RemoveNthNode, TestFromTo2) {
    vector<int> list = {};
    RemoveNthNodeFromEndOfListSolution::ListNode *head = from_list(list);
    vector<int> result = to_list(head);
    EXPECT_EQ(result, list);
}

TEST(RemoveNthNode, Test0) {
    int n = 1;
    vector<int> list = {1, 2, 3};
    vector<int> expected = {1, 2};

    RemoveNthNodeFromEndOfListSolution::ListNode *head, *result;

    head = from_list(list);
    result = solution019->removeNthFromEnd(head, n);
    vector<int> actual = to_list(result);

    EXPECT_EQ(actual, expected);
}

TEST(RemoveNthNode, Test1) {
    int n = 1;
    vector<int> list = {1};
    vector<int> expected = {};

    RemoveNthNodeFromEndOfListSolution::ListNode *head, *result;

    head = from_list(list);
    result = solution019->removeNthFromEnd(head, n);
    vector<int> actual = to_list(result);

    EXPECT_EQ(actual, expected);
}

TEST(RemoveNthNode, Test2) {
    int n = 2;
    vector<int> list = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 2, 3, 5};

    RemoveNthNodeFromEndOfListSolution::ListNode *head, *result;

    head = from_list(list);
    result = solution019->removeNthFromEnd(head, n);
    vector<int> actual = to_list(result);

    EXPECT_EQ(actual, expected);
}

TEST(RemoveNthNode, Test3) {
    int n = 5;
    vector<int> list = {1, 2, 3, 4, 5};
    vector<int> expected = {2, 3, 4, 5};

    RemoveNthNodeFromEndOfListSolution::ListNode *head, *result;

    head = from_list(list);
    result = solution019->removeNthFromEnd(head, n);
    vector<int> actual = to_list(result);

    EXPECT_EQ(actual, expected);
}