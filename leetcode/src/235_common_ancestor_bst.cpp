#include "235_common_ancestor_bst.h"

PathListNode *CommonAncestorBstSolution::find_path(TreeNode *parent, TreeNode *node) {
    if (parent == nullptr) {
        return nullptr;
    }

    PathListNode *result = new PathListNode();
    result->node = parent;

    if (parent->val == node->val) {
        result->next = nullptr;
    } else if (node->val < parent->val) {
        result->next = find_path(parent->left, node);
    } else {
        result->next = find_path(parent->right, node);
    }

    return result;
}

TreeNode *CommonAncestorBstSolution::find_common(PathListNode *p_path,
                                                 PathListNode *q_path) {
    TreeNode *prev = nullptr;

    while (p_path != nullptr && q_path != nullptr &&
           p_path->node == q_path->node) {
        prev = p_path->node;
        p_path = p_path->next;
        q_path = q_path->next;
    }

    return prev;
}

TreeNode *CommonAncestorBstSolution::lowest_common_ancestor_path(TreeNode *root, TreeNode *p, TreeNode *q) {
    PathListNode *p_path = find_path(root, p);
    PathListNode *q_path = find_path(root, q);
    return find_common(p_path, q_path);
}

TreeNode *CommonAncestorBstSolution::lowest_common_ancestor_recursive(TreeNode *root,
        TreeNode *p, TreeNode *q) {
    // should be done once, but ok
    if (p->val > q->val) {
        TreeNode *tmp = p;
        p = q;
        q = tmp;
    }

    if (p->val == root->val || q->val == root->val) {
        return root;
    }

    if (p->val < root->val && q->val > root->val) {
        return root;
    }

    if (q->val < root->val) {
        return lowest_common_ancestor_recursive(root->left, p, q);
    }

    if (p->val > root->val) {
        return lowest_common_ancestor_recursive(root->right, p, q);
    }

    return nullptr; // oops
}

TreeNode *CommonAncestorBstSolution::lowest_common_ancestor_iterative(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (p->val > q->val) {
        TreeNode* tmp = p;
        p = q;
        q = tmp;
    }

    TreeNode *node = root;

    while (true) {
        if (p->val == node->val || q->val == node->val) {
            return node;
        }
        if (p->val < node->val && q->val > node->val) {
            return node;
        }
        if (q->val < node->val) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
}

TreeNode *CommonAncestorBstSolution::lowestCommonAncestor(TreeNode *root, TreeNode *p,
                                                          TreeNode *q) {
    return lowest_common_ancestor_path(root, p, q);
}
