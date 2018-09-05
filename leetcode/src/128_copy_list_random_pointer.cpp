#include "128_copy_list_random_pointer.h"

RandomListNode *CopyListRandomPointerSolution::copy(unordered_map<RandomListNode *, RandomListNode *> &copy_cache,
                                                    RandomListNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (copy_cache[node] != 0) {
        return copy_cache[node];
    }

    RandomListNode *node_copy = new RandomListNode(node->label);
    copy_cache[node] = node_copy;

    node_copy->next = copy(copy_cache, node->next);
    node_copy->random = copy(copy_cache, node->random);

    return node_copy;
}

RandomListNode *CopyListRandomPointerSolution::copyRandomList(RandomListNode *head) {
    unordered_map<RandomListNode *, RandomListNode *> copy_cache;
    return copy(copy_cache, head);
}
