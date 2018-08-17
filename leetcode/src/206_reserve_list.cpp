#include "206_reserve_list.h"

ReverseListSolution::ListNode *
ReverseListSolution::reverse(ReverseListSolution::ListNode *prev, ReverseListSolution::ListNode *node) {
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

ReverseListSolution::ListNode *ReverseListSolution::reverse_recursive(ReverseListSolution::ListNode *head) {
    return reverse(nullptr, head);
}

ReverseListSolution::ListNode *ReverseListSolution::reverse_iterative(ReverseListSolution::ListNode *head) {
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

ReverseListSolution::ListNode *ReverseListSolution::reverseList(ReverseListSolution::ListNode *head) {
    return reverse_iterative(head);
}