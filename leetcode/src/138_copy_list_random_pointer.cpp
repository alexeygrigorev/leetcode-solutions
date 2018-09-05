#include "138_copy_list_random_pointer.h"

RandomListNode *CopyListRandomPointerSolution::copy_iterative(RandomListNode *head) {
    unordered_map<RandomListNode *, RandomListNode *> copy_cache;

    RandomListNode *node = head;
    while (node != nullptr) {
        RandomListNode *copy = new RandomListNode(node->label);
        copy->next = node->next;
        copy->random = node->random;
        copy_cache[node] = copy;
        node = node->next;
    }

    node = copy_cache[head];
    while (node != nullptr) {
        node->next = copy_cache[node->next];
        if (node->random != nullptr) {
            node->random = copy_cache[node->random];
        }
        node = node->next;
    }

    return copy_cache[head];
}

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

