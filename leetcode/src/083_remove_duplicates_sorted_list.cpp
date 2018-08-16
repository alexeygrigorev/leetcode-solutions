#include "083_remove_duplicates_sorted_list.h"

RemoveDuplicatesSortedListSolution::ListNode*
RemoveDuplicatesSortedListSolution::deleteDuplicates(RemoveDuplicatesSortedListSolution::ListNode* head) {
    if (head == nullptr) {
        return head;
    }

    ListNode *prev = head;
    ListNode *node = head->next;

    while (node != nullptr) {
        int prev_value = prev->val;
        int value = node->val;

        if (value == prev_value) {
            prev->next = node->next;
        } else {
            prev = node;
        }

        node = node->next;
    }

    return head;
}