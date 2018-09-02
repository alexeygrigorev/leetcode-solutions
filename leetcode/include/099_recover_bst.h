#include "tree.h"
#include <vector>

using namespace std;

class RecoverBstSolution {
    void traverse(vector<TreeNode *> &nodes, TreeNode *node);
    int find_left(vector<TreeNode *> &nodes);
    int find_right(vector<TreeNode *> &nodes);
    void recoverTree(TreeNode* root);
};
