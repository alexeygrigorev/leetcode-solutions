#include "tree.h"

class CommonAncestorBstSolution {
    struct PathListNode {
        TreeNode *node;
        PathListNode *next;
    };

    PathListNode *find_path(TreeNode *parent, TreeNode *node);
    TreeNode *find_common(PathListNode *p_path, PathListNode *q_path);
    TreeNode *lowest_common_ancestor_path(TreeNode *root, TreeNode *p, TreeNode *q);

    TreeNode *lowest_common_ancestor_recursive(TreeNode *root, TreeNode *p, TreeNode *q);
    TreeNode *lowest_common_ancestor_iterative(TreeNode *root, TreeNode *p, TreeNode *q);

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
};