#include <vector>
#include "list.h"

using namespace std;

class MergeJSortedListsSolution {
public:
    ListNode* merge_naive(vector<ListNode*>& lists);
    ListNode* mergeKLists(vector<ListNode*>& lists);
};
