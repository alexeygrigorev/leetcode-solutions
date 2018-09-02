#include "tree.h"
#include <vector>

using namespace std;

class KthBstElementSolution {
public:
    void traverse_full(vector<int> &values, TreeNode *tree);
    int kth_smallest_naive(TreeNode *root, int k);

    pair<int, bool> traverse(TreeNode *tree, int *cnt, int k);
    int kth_smallest_faster(TreeNode *root, int k);

    int kthSmallest(TreeNode *root, int k);
};