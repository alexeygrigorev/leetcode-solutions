#include <vector>
#include <unordered_map>

#include "001_two_sum.h"

using namespace std;

vector<int> two_sum_naive(vector<int>& nums, int target) {
    int size = nums.size();
    for (int i = 0; i < size - 1; i++) {
        int a = nums[i];
        for (int j = i + 1; j < size; j++) {
            int b = nums[j];
            if (a + b == target) {
                return { i, j };
            }
        }
    }

    // this should not happen
    return { -1, -1 };
}

vector<int> two_sum_hash(vector<int>& nums, int target) {
    unordered_map<int, int> index;
    index[nums[0]] = 0;

    int size = nums.size();
    for (int i = 1; i < size; i++) {
        int a = nums[i];
        int b = target - a;
        if (index.count(b) > 0) {
            return { index[b], i };
        }
        index[a] = i;
    }

    // this should not happen
    return { -1, -1 };
}


vector<int> TwoSumSolution::twoSum(vector<int>& nums, int target) {
    return two_sum_hash(nums, target);
}