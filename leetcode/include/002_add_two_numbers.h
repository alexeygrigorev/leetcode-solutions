#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* number_to_list(long long num);
long long list_to_number(ListNode* list);

void print_list(ListNode* list);

class AddTwoNumbersSolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};