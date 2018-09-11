#include "652_duplicate_subtrees.h"
#include <sstream>

pair<int, long> DuplicateSubtreesSolution::compute_hashes(TreeNode *node, unordered_map<TreeNode *, long> &hashes) {
    if (node == nullptr) {
        return make_pair(0, 0);
    }

    pair<int, long> left = compute_hashes(node->left, hashes);
    pair<int, long> right = compute_hashes(node->right, hashes);

    long hash = node->val;
    hash = 31 * hash + left.first;
    hash = 13 * hash + left.second;
    hash = 37 * hash + right.first;
    hash = 17 * hash + right.second;

    hashes[node] = hash;

    return make_pair(left.second + right.second + 1, hash);
}

bool DuplicateSubtreesSolution::equal_hash(TreeNode *node1, TreeNode *node2, unordered_map<TreeNode *, long> &hashes) {
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }

    if (node1 == nullptr || node2 == nullptr) {
        return false;
    }

    return hashes[node1] == hashes[node2];
}

bool DuplicateSubtreesSolution::equal(TreeNode *node1, TreeNode *node2, unordered_map<TreeNode *, long> &hashes) {
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }

    if (node1 == nullptr || node2 == nullptr) {
        return false;
    }

    return node1->val == node2->val &&
        equal_hash(node1->left, node2->left, hashes) &&
        equal_hash(node1->right, node2->right, hashes) &&
        equal(node1->left, node2->left, hashes) &&
        equal(node1->right, node2->right, hashes);
}

unordered_map<long, vector<TreeNode*>>
DuplicateSubtreesSolution::group_hashes(unordered_map<TreeNode*, long> &hashes) {
    unordered_map<long, vector<TreeNode*>> groups;
    for (auto pair : hashes) {
        groups[pair.second].push_back(pair.first);
    }
    return groups;
}

void DuplicateSubtreesSolution::check_candidates(vector<TreeNode*> &candidates,
        vector<TreeNode*> &result, unordered_map<TreeNode*, long> &hashes) {
    vector<bool> checked(candidates.size(), false);

    for (int i = 0; i < candidates.size() - 1; i++) {
        if (checked[i]) {
            continue;
        }

        TreeNode *candidate = candidates[i];

        bool found = false;
        for (int j = i + 1; j < candidates.size(); j++) {
            TreeNode* other = candidates[j];
            if (equal(candidate, other, hashes)) {
                checked[j] = true;
                found = true;
            }
        }

        if (found) {
            result.push_back(candidate);
        }
    }
}

vector<TreeNode*> DuplicateSubtreesSolution::find_duplicates(unordered_map<TreeNode*, long> &hashes) {
    unordered_map<long, vector<TreeNode*>> groups = group_hashes(hashes);

    vector<TreeNode*> result;

    for (auto pair : groups) {
        vector<TreeNode*> candidates = pair.second;
        if (candidates.size() == 1) {
            continue;
        }

        check_candidates(candidates, result, hashes);
    }

    return result;
}

vector<TreeNode*> DuplicateSubtreesSolution::duplicate_subtrees_hash(TreeNode *root) {
    unordered_map<TreeNode*, long> hashes;
    compute_hashes(root, hashes);
    return find_duplicates(hashes);
}

string DuplicateSubtreesSolution::serialize(TreeNode *node, unordered_map<string, vector<TreeNode*>> &serializations) {
    if (node == nullptr) {
        return "x";
    }

    stringstream repr;

    repr << node->val << "(";
    repr << serialize(node->left, serializations);
    repr << ",";
    repr << serialize(node->right, serializations);
    repr << ")";

    string result = repr.str();
    serializations[result].push_back(node);

    return result;
}

vector<TreeNode*> DuplicateSubtreesSolution::duplicate_subtrees_serialization(TreeNode *root) {
    unordered_map<string, vector<TreeNode*>> serializations;
    serialize(root, serializations);

    vector<TreeNode*> result;
    for (auto pair : serializations) {
        vector<TreeNode*> candidates = pair.second;

        if (candidates.size() > 1) {
            result.push_back(candidates[0]);
        }
    }

    return result;
}

vector<TreeNode*> DuplicateSubtreesSolution::findDuplicateSubtrees(TreeNode *root) {
    return duplicate_subtrees_hash(root);
}
