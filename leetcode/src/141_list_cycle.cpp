#include "141_list_cycle.h"

bool ListCycleSolution::hasCycle(ListNode *head) {
    if (head == nullptr) {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != nullptr) {
        if (fast == slow) {
            return true;
        }

        slow = slow->next;
        fast = fast->next;

        if (fast == nullptr) {
            break;
        }

        if (fast == slow) {
            return true;
        }

        fast = fast->next;
    }

    return false;
}
