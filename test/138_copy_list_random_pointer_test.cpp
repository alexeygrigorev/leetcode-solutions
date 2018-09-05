#include "138_copy_list_random_pointer.h"
#include "gtest/gtest.h"

using namespace std;

CopyListRandomPointerSolution *solution128 = new CopyListRandomPointerSolution;


TEST(CopyListRandomPointer, Test0) {
    auto node1 = new RandomListNode(1);
    auto node2 = new RandomListNode(2);
    auto node3 = new RandomListNode(3);
    auto node4 = new RandomListNode(4);
    auto node5 = new RandomListNode(5);

    node1->next = node2;
    node1->random = node5;

    node2->next = node3;
    node2->random = node1;

    node3->next = node4;
    node3->random = node1;

    node4->next = node5;
    node4->random = nullptr;

    node5->next = nullptr;
    node5->random = node5;

    solution128->copyRandomList(node1);
}

TEST(CopyListRandomPointer, Test1) {
    auto node1 = new RandomListNode(1);
    node1->next = nullptr;
    node1->random = node1;

    solution128->copyRandomList(node1);
}
