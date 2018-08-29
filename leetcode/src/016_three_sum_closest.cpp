#include <algorithm>
#include "limits.h"
#include "016_three_sum_closest.h"

int ThreeSumClosestSolution::threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int min_diff = INT_MAX;

    for (int i = 0; i < n - 2; i++) {
        int a = nums[0];

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int b = nums[j];
            int c = nums[k];
            int sum = a + b + c;

        }

    }

    return 0;
}
