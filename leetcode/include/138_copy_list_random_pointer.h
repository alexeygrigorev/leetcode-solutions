#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {};
};

class CopyListRandomPointerSolution {
public:
    RandomListNode *copy_iterative(RandomListNode *head);
    RandomListNode *copy(unordered_map<RandomListNode *, RandomListNode *> &copy_cache,
                         RandomListNode *node);
    RandomListNode *copyRandomList(RandomListNode *head);
};