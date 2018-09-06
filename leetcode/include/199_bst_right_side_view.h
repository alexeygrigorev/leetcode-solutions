#include "tree.h"
#include <vector>

using namespace std;

class BstRightViewSolution {
public:
    void traverse(TreeNode *node, int level, vector<vector<int>> &values);
    vector<int> rightSideView(TreeNode *root);
};