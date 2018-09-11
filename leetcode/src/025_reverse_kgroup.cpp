#include "025_reverse_kgroup.h"

ListNode *Solution::next_group_end(ListNode *start, int k) {
    ListNode *node = start;
    int cnt = 1; // start is already included

    while (cnt < k && node != nullptr) {
        node = node->next;
        cnt++;
    }

    return node;
}

void Solution::reverse(ListNode *start, ListNode *end) {
    ListNode *prev = nullptr;
    ListNode *node = start;
    ListNode *next = nullptr;

    ListNode *last = nullptr;
    if (end != nullptr) {
        last = end->next;
    }

    while (node != last) {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
}

ListNode *Solution::reverse_each_group(ListNode *head, int k) {
    if (head == nullptr || k == 1) {
        return head;
    }

    ListNode *dummy = new ListNode(31337);
    ListNode *prev = dummy;

    ListNode *group_start = head;
    ListNode *group_end;
    ListNode *next;

    while (group_start != nullptr) {
        group_end = next_group_end(group_start, k);

        if (group_end == nullptr) {
            prev->next = group_start;
            break;
        }

        next = group_end->next;

        reverse(group_start, group_end);

        prev->next = group_end;
        prev = group_start;

        group_start = next;
    }

    ListNode *result = dummy->next;
    delete dummy;
    return result;
}
