#include "002_add_two_numbers.h"
#include "gtest/gtest.h"

using namespace std;

AddTwoNumbersSolution *solution002 = new AddTwoNumbersSolution;

bool lists_eq(ListNode *a, ListNode *b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    return a->val == b->val && lists_eq(a->next, b->next);
}


TEST(AddTwoNumbers, number_to_list_0) {
    ListNode* actual = number_to_list(342);
    ListNode* expected = new ListNode(2, new ListNode(4, new ListNode(3)));
    print_list(actual);
    print_list(expected);
    EXPECT_TRUE(lists_eq(actual, expected));
}

TEST(AddTwoNumbers, number_to_list_1) {
    ListNode* actual = number_to_list(3);
    ListNode* expected = new ListNode(3);
    EXPECT_TRUE(lists_eq(actual, expected));
}

TEST(AddTwoNumbers, number_to_list_2) {
    ListNode* actual = number_to_list(0);
    ListNode* expected = new ListNode(0);
    EXPECT_TRUE(lists_eq(actual, expected));
}

TEST(AddTwoNumbers, number_to_list_3) {
    ListNode* actual = number_to_list(1000);
    ListNode* expected = new ListNode(0,
                         new ListNode(0,
                         new ListNode(0,
                         new ListNode(1))));
    EXPECT_TRUE(lists_eq(actual, expected));
}

TEST(AddTwoNumbers, list_to_number_0) {
    ListNode* list = new ListNode(0,
                     new ListNode(0,
                     new ListNode(0,
                     new ListNode(1))));
    int actual = list_to_number(list);
    EXPECT_EQ(actual, 1000);
}

TEST(AddTwoNumbers, Test0) {
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* actual = solution002->addTwoNumbers(l1, l2);
    ListNode* expected = new ListNode(7, new ListNode(0, new ListNode(8)));
    print_list(actual);
    print_list(expected);
    EXPECT_TRUE(lists_eq(actual, expected));
}

TEST(AddTwoNumbers, Test1) {
    ListNode* l1 = number_to_list(981);
    ListNode* l2 = number_to_list(0);
    ListNode* actual = solution002->addTwoNumbers(l1, l2);
    ListNode* expected = number_to_list(981);
    print_list(actual);
    print_list(expected);
    EXPECT_TRUE(lists_eq(actual, expected));
}

TEST(AddTwoNumbers, Test2) {
    ListNode* l1 = number_to_list(999);
    ListNode* l2 = number_to_list(1);
    ListNode* actual = solution002->addTwoNumbers(l1, l2);
    ListNode* expected = number_to_list(1000);
    EXPECT_TRUE(lists_eq(actual, expected));
}

TEST(AddTwoNumbers, Test3) {
    ListNode* l1 = number_to_list(99999999);
    ListNode* l2 = number_to_list(99999999);
    ListNode* actual = solution002->addTwoNumbers(l1, l2);
    ListNode* expected = number_to_list(199999998);
    EXPECT_TRUE(lists_eq(actual, expected));
}

TEST(AddTwoNumbers, Test4) {
    ListNode* l1 = number_to_list(9);
    ListNode* l2 = number_to_list(9999999991);
    ListNode* actual = solution002->addTwoNumbers(l1, l2);
    ListNode* expected = number_to_list(10000000000);
    print_list(expected);
    print_list(actual);
    EXPECT_TRUE(lists_eq(actual, expected));
}
