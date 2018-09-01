#include "tree.h"
#include <vector>

using namespace std;

class TreeLevelTraversalSolution {
public:
    void traverse(vector <vector<int>> &result, int level, TreeNode *node);
    vector <vector<int>> levelOrder(TreeNode *root);
};