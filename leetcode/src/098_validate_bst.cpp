#include "098_validate_bst.h"

void ValidateBstSolution::traverse(vector<int> &nodes, TreeNode *tree) {
    if (tree == nullptr) {
        return;
    }
    traverse(nodes, tree->left);
    nodes.push_back(tree->val);
    traverse(nodes, tree->right);
}

bool ValidateBstSolution::isValidBST(TreeNode *root) {
    vector<int> nodes;
    traverse(nodes, root);

    for (int i = 1; i < nodes.size(); i++) {
        if (nodes[i - 1] >= nodes[i]) {
            return false;
        }
    }

    return true;
}
