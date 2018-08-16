#include <string>

#include "019_remove_nth_node.h"

using namespace std;

RemoveNthNodeFromEndOfListSolution::ListNode *RemoveNthNodeFromEndOfListSolution::removeNthFromEnd(ListNode *head, int n) {
    int len = 0;
    ListNode *node = head;
    while (node != nullptr) {
        node = node->next;
        len++;
    }

    if (len == n) {
        return head->next;
    }

    int c = 0;
    int num = len - n - 1;
    node = head;
    while (c < num) {
        node = node->next;
        c++;
    }

    if (node->next != nullptr) {
        node->next = node->next->next;
    }

    return head;
}