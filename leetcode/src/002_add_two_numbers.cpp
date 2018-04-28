#include <string>
#include <iostream>

#include "002_add_two_numbers.h"

using namespace std;

ListNode* number_to_list(long long num) {
    int mod = num % 10;
    long long div = num / 10;

    ListNode* last_digit = new ListNode(mod);
    ListNode* current = last_digit;

    while (div != 0) {
        mod = div % 10;
        div = div / 10;
        ListNode* next = new ListNode(mod);
        current->next = next;
        current = next;
    }

    return last_digit;
}

long long list_to_number(ListNode* list) {
    if (list == NULL) {
        return 0;
    }
    return list->val + list_to_number(list->next) * 10;
}

void print_list(ListNode* list) {
    ListNode* start = list;
    while (start != NULL) {
        cout << start->val << " ";
        start = start->next;
    }
    cout << endl;
}

ListNode* add_two_numbers_naive(ListNode* l1, ListNode* l2) {
    long long num = list_to_number(l1) + list_to_number(l2);
    return number_to_list(num);
}

int zero_or_val(ListNode* list) {
    if (list == NULL) {
        return 0;
    }
    return list->val;
}

ListNode* null_or_next(ListNode* list) {
    if (list == NULL) {
        return NULL;
    }
    return list->next;
}

ListNode* add_school_algo(ListNode* l1, ListNode* l2, int carry) {
    if (l1 == NULL && l2 == NULL) {
        if (carry == 0) {
            return NULL;
        } else {
            return new ListNode(carry);
        }
    }

    int res = zero_or_val(l1) + zero_or_val(l2) + carry;
    int carry_next = 0;
    while (res >= 10) {
        res = res - 10;
        carry_next = carry_next + 1;
    }

    ListNode* result = new ListNode(res);
    result->next = add_school_algo(null_or_next(l1), null_or_next(l2), carry_next);
    return result;
}

ListNode* AddTwoNumbersSolution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    //return add_two_numbers_naive(l1, l2);
    return add_school_algo(l1, l2, 0);
}
