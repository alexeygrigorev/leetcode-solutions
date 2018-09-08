#include "236_common_ancestor.h"

bool CommonAncestorSolution::has_element(TreeNode *parent, TreeNode *node) {
    if (parent == nullptr) {
        return false;
    }

    if (parent->val == node->val) {
        return true;
    }

    return has_element(parent->left, node) || has_element(parent->right, node);
}

TreeNode *CommonAncestorSolution::common_ancestor_naive(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (has_element(root->left, p) && has_element(root->left, q)) {
        return common_ancestor_naive(root->left, p, q);
    }

    if (has_element(root->right, p) && has_element(root->right, q)) {
        return common_ancestor_naive(root->right, p, q);
    }

    return root;
}

bool CommonAncestorSolution::has_element_memo(TreeNode *parent, TreeNode *node, unordered_map<int, bool> &memo) {
    if (parent == nullptr) {
        return false;
    }

    int val = parent->val;

    if (val == node->val) {
        memo[val] = true;
        return true;
    }

    bool result = has_element_memo(parent->left, node, memo) ||
                  has_element_memo(parent->right, node, memo);
    memo[val] = result;
    return result;
}

TreeNode *CommonAncestorSolution::common_memo(TreeNode *root, unordered_map<int, bool> &memo_p,
                                              unordered_map<int, bool> &memo_q) {
    if (root->left != nullptr) {
        int val = root->left->val;
        if (memo_p[val] && memo_q[val]) {
            return common_memo(root->left, memo_p, memo_q);
        }
    }

    if (root->right != nullptr) {
        int val = root->right->val;
        if (memo_p[val] && memo_q[val]) {
            return common_memo(root->right, memo_p, memo_q);
        }
    }

    return root;
}

TreeNode *CommonAncestorSolution::common_ancestor_memo(TreeNode *root, TreeNode *p, TreeNode *q) {
    unordered_map<int, bool> memo_p;
    has_element_memo(root, p, memo_p);

    unordered_map<int, bool> memo_q;
    has_element_memo(root, q, memo_q);

    return common_memo(root, memo_p, memo_q);
}

TreeNode *CommonAncestorSolution::common_ancestor_recursive(TreeNode *root, TreeNode *p, TreeNode *q) {
    // idea:
    // we need to find the split - when paths to p and q diverge
    //
    // if both left and right return non-null
    // then p (or q) is on the left and q (or p) is on the right - so branches diverge
    //
    // if one is null, and another is not-null
    // then we look follow non-null to look for the split

    if (root == nullptr) {
        return nullptr;
    }

    if (root == p || root == q) {
        return root;
    }

    TreeNode *left = common_ancestor_recursive(root->left, p, q);
    TreeNode *right = common_ancestor_recursive(root->right, p, q);

    if (left != nullptr && right != nullptr) {
        return root;
    }

    if (left != nullptr) {
        return left;
    }

    if (right != nullptr) {
        return right;
    }

    return nullptr;
}

TreeNode *CommonAncestorSolution::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return common_ancestor_recursive(root, p, q);
}
