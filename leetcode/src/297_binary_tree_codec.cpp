#include "297_binary_tree_codec.h"

void BinaryTreeCodec::traverse_serialize(TreeNode *node, stringstream &ss) {
    if (node == nullptr) {
        ss << "x";
        return;
    }

    ss << node->val << "(";
    traverse_serialize(node->left, ss);
    ss << ",";
    traverse_serialize(node->right, ss);
    ss << ")";
}

string BinaryTreeCodec::serialize(TreeNode *root) {
    stringstream ss;
    traverse_serialize(root, ss);
    return ss.str();
}

TreeNode *BinaryTreeCodec::parse_recursive(string &data, int *pos) {
    if (data[*pos] == 'x') {
        *pos = *pos + 1;
        return nullptr;
    }

    bool minus = false;
    if (data[*pos] == '-') {
        minus = true;
        *pos = *pos + 1;
    }

    int val = 0;
    while (data[*pos] >= '0' && data[*pos] <= '9') {
        val = val * 10 + (data[*pos] - '0');
        *pos = *pos + 1;
    }

    if (minus) {
        val = -val;
    }

    TreeNode *node  = new TreeNode(val);
    // now have '('
    *pos = *pos + 1;
    node->left = parse_recursive(data, pos);

    // now have ','
    *pos = *pos + 1;
    node->right = parse_recursive(data, pos);

    // now have ')'
    *pos = *pos + 1;

    return node;
}

TreeNode *BinaryTreeCodec::deserialize(string data) {
    int pos = 0;
    return parse_recursive(data, &pos);
}
