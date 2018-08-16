#include "160_intersection_of_two_lists.h"

IntersectionOfTwoListsSolution::ListNode *
IntersectionOfTwoListsSolution::getIntersectionNode(IntersectionOfTwoListsSolution::ListNode *headA,
                                                    IntersectionOfTwoListsSolution::ListNode *headB) {
    int len1 = 1;
    ListNode *last1 = headA;
    while (last1 != nullptr) {
        len1++;
        last1 = last1->next;
    }

    int len2 = 1;
    ListNode *last2 = headB;
    while (last2 != nullptr) {
        len2++;
        last2 = last2->next;
    }

    if (last1 != last2) {
        return nullptr;
    }

    ListNode *start1 = headA;
    ListNode *start2 = headB;

    while (len1 > len2) {
        start1 = start1->next;
        len1--;
    }
    while (len2 > len1) {
        start2 = start2->next;
        len2--;
    }

    while (start1 != start2) {
        start1 = start1->next;
        start2 = start2->next;
    }

    return start1;
}
