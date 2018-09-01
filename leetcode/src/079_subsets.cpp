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

void SubsetsSolution::recursion(vector<vector<int>> &result, vector<int> &tmp, vector<int> &nums, int i) {
    vector<int> copy = tmp;
    result.push_back(copy);

    for (int j = i; j < nums.size(); j++) {
        tmp.push_back(nums[j]);
        recursion(result, tmp, nums, j + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> SubsetsSolution::subset_recursion(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> tmp_list;
    recursion(result, tmp_list, nums, 0);
    return result;
}

vector<vector<int>> SubsetsSolution::subsets(vector<int> &nums) {
    return subset_bits(nums);
}

vector<vector<int>> SubsetsSolution::subset_iterative(vector<int> &nums) {
    vector<vector<int>> result = {{}};

    for (int i = 0; i < nums.size(); i++) {
        int cur_size = result.size();

        for (int j = 0; j < cur_size; j++) {
            vector<int> copy = result[j];
            copy.push_back(nums[i]);
            result.push_back(copy);
        }
    }

    return result;
}
