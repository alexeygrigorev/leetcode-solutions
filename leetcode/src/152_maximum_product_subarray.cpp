#include <vector>
#include <cstdio>
#include "limits.h"
#include "152_maximum_product_subarray.h"

using namespace std;

int max_product_naive(vector<int> &nums) {
    int max_prod = INT_MIN;
    int len = nums.size();

    for (int i = 0; i < len; i++) {
        int prod = 1;
        for (int j = i; j < len; j++) {
            prod = prod * nums[j];
            if (prod > max_prod) {
                printf("s=%d: %d to %d\n", prod, i, j);
                max_prod = prod;
            }
        }
    }

    return max_prod;
}

int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

int min3(int a, int b, int c) {
    return min(a, min(b, c));
}


int max_product_dp(vector<int> &nums) {
    int len = nums.size();

    int max_global = nums[0];
    int max_prev = nums[0];
    int min_prev = nums[0];

    for (int i = 1; i < len; i++) {
        int num = nums[i];
        int max_current = max3(num, num * min_prev, num * max_prev);
        int min_current = min3(num, num * min_prev, num * max_prev);

        if (max_current > max_global) {
            max_global = max_current;
        }

        min_prev = min_current;
        max_prev = max_current;
    }

    return max_global;
}

int MaximumProductSubarraySolution::maxProduct(vector<int> &nums) {
    return max_product_dp(nums);
}