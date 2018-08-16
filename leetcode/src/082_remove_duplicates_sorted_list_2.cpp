#include "082_remove_duplicates_sorted_list_2.h"

RemoveDuplicatesSortedList2Solution::ListNode *
RemoveDuplicatesSortedList2Solution::deleteDuplicates(RemoveDuplicatesSortedList2Solution::ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    if (head->val == head->next->val) {
        int value = head->val;
        RemoveDuplicatesSortedList2Solution::ListNode *next = head->next;
        while (next != nullptr && next->val == value) {
            next = next->next;
        }

        return deleteDuplicates(next);
    }

    head->next = deleteDuplicates(head->next);
    return head;
}
