#include <vector>

using namespace std;

class SubsetsSolution {
public:
    vector<vector<int>> subset_bits(vector<int> &nums);
    void recursion(vector<vector<int>> &result, vector<int> &tmp, vector<int> &nums, int i);
    vector<vector<int>> subset_recursion(vector<int> &nums);
    vector<vector<int>> subset_iterative(vector<int> &nums);
    vector<vector<int>> subsets(vector<int> &nums);
};