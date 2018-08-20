#include "list.h"

ListNode *from_list(vector<int> &list) {
    if (list.empty()) {
        return nullptr;
    }

    ListNode *head, *prev, *next;

    head = new ListNode();
    head->val = list[0];
    head->next = nullptr;
    prev = head;

    for (int i = 1; i < list.size(); i++) {
        next = new ListNode;
        next->val = list[i];
        next->next = nullptr;

        prev->next = next;
        prev = next;
    }

    return head;
}

vector<int> to_list(ListNode *head) {
    vector<int> result;

    ListNode *node = head;

    while (node != nullptr) {
        result.push_back(node->val);
        node = node->next;
    }

    return result;
}