#include "tree.h"
#include <unordered_map>

using namespace std;

class CommonAncestorSolution {
    bool has_element(TreeNode* parent, TreeNode *node);
    TreeNode *common_ancestor_naive(TreeNode *root, TreeNode *p, TreeNode *q);

    bool has_element_memo(TreeNode *parent, TreeNode *node, unordered_map<int, bool> &memo);
    TreeNode *common_memo(TreeNode *root, unordered_map<int, bool> &memo_p,
                          unordered_map<int, bool> &memo_q);

    TreeNode *common_ancestor_memo(TreeNode *root, TreeNode *p, TreeNode *q);

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
};