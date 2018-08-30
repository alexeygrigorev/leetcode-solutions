#include <algorithm>
#include <climits>
#include "016_three_sum_closest.h"

int ThreeSumClosestSolution::threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int min_diff = INT_MAX;
    int best_sum = -1;

    for (int i = 0; i < n - 2; i++) {
        int a = nums[i];

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int b = nums[j];
            int c = nums[k];
            int sum = a + b + c;

            int diff = abs(sum - target);

            if (diff == 0) {
                return sum;
            }

            if (diff < min_diff) {
                min_diff = diff;
                best_sum = sum;
            }

            if (sum > target) {
                k--;
            } else { // sum < target
                j++;
            }
        }
    }

    return best_sum;
}
