#include "199_bst_right_side_view.h"

void BstRightViewSolution::traverse(TreeNode *node, int level, vector<vector<int>> &values) {
    if (node == nullptr) {
        return;
    }

    while (values.size() <= level) {
        values.push_back({});
    }

    traverse(node->left, level + 1, values);
    values[level].push_back(node->val);
    traverse(node->right, level + 1, values);
}

vector<int> BstRightViewSolution::rightSideView(TreeNode *root) {
    vector<vector<int>> values;
    traverse(root, 0, values);

    vector<int> result;
    for (vector<int> vec : values) {
        int val = vec.back();
        result.push_back(val);
    }
    return result;
}


