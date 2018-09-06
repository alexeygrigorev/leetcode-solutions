#include "234_palindrome_list.h"

ListNode *PalindromeListSolution::reverse_copy(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *node = head;
    ListNode *result = new ListNode(head->val);

    while (node != nullptr) {
        ListNode *copy = new ListNode(node->val);
        copy->next = result;
        result = copy;
        node = node->next;
    }

    return result;
}

bool PalindromeListSolution::palindrome(ListNode *head1, ListNode *head2) {
    ListNode *node1 = head1;
    ListNode *node2 = head2;

    while (node1 != nullptr && node2 != nullptr) {
        if (node1->val != node2->val) {
            return false;
        }
        node1 = node1->next;
        node2 = node2->next;
    }

    return true;
}

bool PalindromeListSolution::is_palindrome_copy(ListNode *head) {
    ListNode *reversed = reverse_copy(head);
    return palindrome(head, reversed);
}

ListNode *PalindromeListSolution::cut_half(ListNode *head) {
    ListNode *slow_prev = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;

    int slow_cnt = 1;
    int fast_cnt = 1;

    while (fast != nullptr) {
        fast = fast->next;
        fast_cnt++;
        if (fast == nullptr) {
            break;
        }
        slow_prev = slow;
        slow = slow->next;
        slow_cnt++;

        fast = fast->next;
        fast_cnt++;
    }

    if (slow_prev != nullptr) {
        slow_prev->next = nullptr;
    }

    if (fast_cnt % 2 == 1) {
        return slow;
    } else {
        return slow->next;
    }
}

ListNode *PalindromeListSolution::reverse_inplace(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *prev = nullptr;
    ListNode *node = head;
    ListNode *next = nullptr;

    while (node != nullptr) {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }

    return prev;
}

bool PalindromeListSolution::is_palindrome_split(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    ListNode *middle = cut_half(head);
    middle = reverse_inplace(middle);

    return palindrome(head, middle);
}

bool PalindromeListSolution::isPalindrome(ListNode *head) {
    return is_palindrome_copy(head);
}
