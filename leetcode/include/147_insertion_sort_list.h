class InsertionSortListSolution {
public:
    struct ListNode {
        int val;
        ListNode *next;
    };

    ListNode* find_min(ListNode* head);
    ListNode* bubble(ListNode* head);

    ListNode* insertion_inplace(ListNode* head);

    ListNode* insertionSortList(ListNode* head);
};