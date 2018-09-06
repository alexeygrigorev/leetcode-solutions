#include "list.h"

class PalindromeListSolution {
    ListNode *reverse_copy(ListNode *head);
    bool palindrome(ListNode *head1, ListNode *head2);
    bool is_palindrome_copy(ListNode *head);

    ListNode *cut_half(ListNode *head);
    ListNode *reverse_inplace(ListNode *head);
    bool is_palindrome_split(ListNode *head);

    bool isPalindrome(ListNode *head);
};