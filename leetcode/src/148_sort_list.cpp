#include <148_sort_list.h>


ListNode *SortListSolution::find_middle(ListNode *head) {
    ListNode *prev_slow = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next;
        }
    }

    ListNode *result = prev_slow->next;
    prev_slow->next = nullptr;
    return result;
}

ListNode *SortListSolution::merge(ListNode *first, ListNode *second) {
    ListNode *head = nullptr;

    if (first->val < second->val) {
        head = first;
        first = first->next;
    } else {
        head = second;
        second = second->next;
    }

    ListNode *prev = head;

    while (first != nullptr && second != nullptr) {
        if (first->val < second->val) {
            prev->next = first;
            first = first->next;
        } else {
            prev->next = second;
            second = second->next;
        }
        prev = prev->next;
    }

    while (first != nullptr) {
        prev->next = first;
        prev = prev->next;
        first = first->next;
    }

    while (second != nullptr) {
        prev->next = second;
        prev = prev->next;
        second = second->next;
    }

    return head;
}

ListNode *SortListSolution::merge_sort(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *middle = find_middle(head);
    head = merge_sort(head);
    middle = merge_sort(middle);

    return merge(head, middle);
}

ListNode *SortListSolution::sortList(ListNode *head) {
    return merge_sort(head);
}