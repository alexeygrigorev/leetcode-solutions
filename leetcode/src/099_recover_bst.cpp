#include "099_recover_bst.h"

void RecoverBstSolution::traverse(vector<TreeNode *> &nodes, TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    traverse(nodes, node->left);
    nodes.push_back(node);
    traverse(nodes, node->right);
}

int RecoverBstSolution::find_left(vector<TreeNode *> &nodes) {
    for (int i = 0; i < nodes.size() - 1; i++) {
        if (nodes[i]->val > nodes[i + 1]->val) {
            return i;
        }
    }

    return -1;
}

int RecoverBstSolution::find_right(vector<TreeNode *> &nodes) {
    for (int i = nodes.size() - 1; i >= 1; i--) {
        if (nodes[i]->val < nodes[i - 1]->val) {
            return i;
        }
    }

    return -1;
}

void RecoverBstSolution::recoverTree(TreeNode *root) {
    vector<TreeNode *> nodes;
    traverse(nodes, root);

    int left = find_left(nodes);
    int right = find_right(nodes);

    int tmp = nodes[left]->val;
    nodes[left]->val = nodes[right]->val;
    nodes[right]->val = tmp;
}
