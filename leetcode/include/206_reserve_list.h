class ReverseListSolution {
public:
    struct ListNode {
        int val;
        ListNode *next;
    };

    ListNode* reverse(ListNode* prev, ListNode* node);
    ListNode* reverse_recursive(ListNode* head);

    ListNode* reverse_iterative(ListNode* head);

    ListNode* reverseList(ListNode* head);
};