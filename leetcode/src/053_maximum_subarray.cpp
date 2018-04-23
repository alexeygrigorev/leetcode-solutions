#include <vector>
#include <limits.h>
#include <debug.h>

#include "053_maximum_subarray.h"

using namespace std;


int max_sum_naive(vector<int> &nums) {
    int max_sum = INT_MIN;
    int len = nums.size();

    for (int i = 0; i < len; i++) {
        int sum = 0;
        for (int j = i; j < len; j++) {
            sum = sum + nums[j];
            if (sum > max_sum) {
                printf("s=%d: %d to %d\n", sum, i, j);
                max_sum = sum;
            }
        }
    }

    return max_sum;
}

int max_sum_iterating(vector<int> &nums) {
    return 0;
}

int MaximumSubarraySolution::maxSubArray(vector<int> &nums) {
    return max_sum_iterating(nums);
}