#include "tree.h"
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class DuplicateSubtreesSolution {
public:
    pair<int, long> compute_hashes(TreeNode *node, unordered_map<TreeNode *, long> &hashes);
    bool equal_hash(TreeNode *node1, TreeNode *node2, unordered_map<TreeNode*, long> &hashes);
    bool equal(TreeNode *node1, TreeNode *node2, unordered_map<TreeNode*, long> &hashes);
    unordered_map<long, vector<TreeNode*>> group_hashes(unordered_map<TreeNode*, long> &hashes);
    void check_candidates(vector<TreeNode*> &candidates, vector<TreeNode*> &result,
                         unordered_map<TreeNode*, long> &hashes);
    vector<TreeNode*> find_duplicates(unordered_map<TreeNode*, long> &hashes);

    vector<TreeNode*> duplicate_subtrees_hash(TreeNode* root);

    string serialize(TreeNode *node, unordered_map<string, vector<TreeNode*>> &serializations);
    vector<TreeNode*> duplicate_subtrees_serialization(TreeNode* root);

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
};