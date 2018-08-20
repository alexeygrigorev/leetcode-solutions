#include "list.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Lists, TestFromTo) {
    vector<int> list = {1, 2, 3};
    ListNode *head = from_list(list);
    vector<int> result = to_list(head);
    EXPECT_EQ(result, list);
}

TEST(Lists, TestFromTo2) {
    vector<int> list = {};
    ListNode *head = from_list(list);
    vector<int> result = to_list(head);
    EXPECT_EQ(result, list);
}
