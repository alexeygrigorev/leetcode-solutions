#include "102_tree_level_traversal.h"

void TreeLevelTraversalSolution::traverse(vector<vector<int>> &result, int level, TreeNode *node) {
    while (result.size() <= level) {
        result.push_back({});
    }

    if (node->left != nullptr) {
        traverse(result, level + 1, node->left);
    }
    result[level].push_back(node->val);
    if (node->right != nullptr) {
        traverse(result, level + 1, node->right);
    }
}

vector<vector<int>> TreeLevelTraversalSolution::levelOrder(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }

    vector<vector<int>> result;
    traverse(result, 0, root);
    return result;
}
