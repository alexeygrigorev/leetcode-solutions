#include "tree.h"
#include <vector>

using namespace std;

class ValidateBstSolution {
public:
    void traverse(vector<int> &nodes, TreeNode *tree);
    bool isValidBST(TreeNode *root);
};