#include "206_reserve_list.h"

ListNode * ReverseListSolution::reverse(ListNode *prev, ListNode *node) {
    if (node == nullptr) {
        return node;
    }

    ListNode *next = node->next;
    node->next = prev;

    if (next == nullptr) {
        return node;
    }

    return reverse(node, next);
}

ListNode *ReverseListSolution::reverse_recursive(ListNode *head) {
    return reverse(nullptr, head);
}

ListNode *ReverseListSolution::reverse_iterative(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *prev = nullptr;
    ListNode *node = head;
    ListNode *next;

    while (node != nullptr) {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }

    return prev;
}

ListNode *ReverseListSolution::reverseList(ListNode *head) {
    return reverse_iterative(head);
}