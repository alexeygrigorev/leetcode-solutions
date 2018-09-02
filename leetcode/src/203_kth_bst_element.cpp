#include "203_kth_bst_element.h"

void KthBstElementSolution::traverse_full(vector<int> &values, TreeNode *tree) {
    if (tree == nullptr) {
        return;
    }

    traverse_full(values, tree->left);
    values.push_back(tree->val);
    traverse_full(values, tree->right);
}

int KthBstElementSolution::kth_smallest_naive(TreeNode *root, int k) {
    vector<int> values;
    traverse_full(values, root);
    return values[k - 1];
}

int KthBstElementSolution::kthSmallest(TreeNode *root, int k) {
    return 0;
}

pair<int, bool> KthBstElementSolution::traverse(TreeNode *tree, int *cnt, int k) {
    pair<int, bool> res;

    if (tree->left != nullptr) {
        res = traverse(tree->left, cnt, k);
        if (res.second == true) {
            return res;
        }
    }

    *cnt = *cnt + 1;
    if (*cnt == k) {
        return make_pair(tree->val, true);
    }

    if (tree->right != nullptr) {
        res = traverse(tree->right, cnt, k);
        if (res.second == true) {
            return res;
        }
    }

    return make_pair(0, false);
}

int KthBstElementSolution::kth_smallest_faster(TreeNode *root, int k) {
    int cnt = 0;
    pair<int, bool> result = traverse(root, &cnt, k);
    return result.first;
}
