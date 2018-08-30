#include "023_merge_k_sorted_lists.h"
#include <queue>

ListNode *MergeJSortedListsSolution::merge_naive(vector<ListNode *> &lists) {
    for (int i = lists.size() - 1; i >= 0; i--) {
        if (lists[i] == nullptr) {
            lists.erase(lists.begin() + i);
        }
    }

    ListNode *head = new ListNode(31337);
    ListNode *node = head;

    while (!lists.empty()) {
        int min_idx = 0;
        int min = lists[0]->val;

        int n = lists.size();
        for (int i = 1; i < n; i++) {
            ListNode *n = lists[i];

            if (min > n->val) {
                min_idx = i;
                min = n->val;
            }
        }

        ListNode *best = lists[min_idx];
        if (best->next != nullptr) {
            lists[min_idx] = best->next;
        } else {
            lists.erase(lists.begin() + min_idx);
        }

        best->next = nullptr;
        node->next = best;
        node = best;
    }

    return head->next;
}

struct ListNodeComparer {
    bool operator() (ListNode *left, ListNode *right) const {
        return left->val > right->val;
    }
};

ListNode *MergeJSortedListsSolution::merge_heap(vector<ListNode *> &lists) {
    priority_queue<ListNode*, vector<ListNode*>, ListNodeComparer> heap;

    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != nullptr) {
            heap.emplace(lists[i]);
        }
    }

    ListNode *head = new ListNode(31337);
    ListNode *node = head;

    while (!heap.empty()) {
        ListNode *best = heap.top();
        heap.pop();

        if (best->next != nullptr) {
            heap.emplace(best->next);
        }

        best->next = nullptr;
        node->next = best;
        node = best;
    }

    return head->next;
}

ListNode *MergeJSortedListsSolution::mergeKLists(vector<ListNode *> &lists) {
    return merge_heap(lists);
}
