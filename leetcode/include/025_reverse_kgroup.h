#include "list.h"

class Solution {
public:
    ListNode *next_group_end(ListNode *start, int k);
    void reverse(ListNode *start, ListNode *end);
    ListNode *reverse_each_group(ListNode *head, int k);

    ListNode *reverseKGroup(ListNode *head, int k);
};