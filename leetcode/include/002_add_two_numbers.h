#include <string>
#include "list.h"

using namespace std;

ListNode* number_to_list(long long num);
long long list_to_number(ListNode* list);

void print_list(ListNode* list);

class AddTwoNumbersSolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};