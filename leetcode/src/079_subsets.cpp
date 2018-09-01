#include "079_subsets.h"

vector<vector<int>> SubsetsSolution::subset_bits(vector<int> &nums) {
    int n = nums.size();
    int max = 1 << (n + 1) - 1;

    vector<vector<int>> result;
    for (int i = 0; i < max; i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                subset.push_back(nums[j]);
            }
        }
        result.push_back(subset);

    }
    return result;
}

vector<vector<int>> SubsetsSolution::subsets(vector<int> &nums) {
    return subset_bits(nums);
}
