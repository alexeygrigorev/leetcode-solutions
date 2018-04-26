#include <vector>
#include <cstdio>

#include "152_maximum_product_subarray.h"

using namespace std;

int max_product_naive(vector<int> &nums) {
    int max_prod = 0;
    int len = nums.size();

    for (int i = 0; i < len; i++) {
        int prod = nums[i];
        for (int j = i + 1; j < len; j++) {
            prod = prod * nums[j];
            if (prod > max_prod) {
                printf("s=%d: %d to %d\n", prod, i, j);
                max_prod = prod;
            }
        }
    }

    return max_prod;
}


int MaximumProductSubarraySolution::maxProduct(vector<int> &nums) {
    return max_product_naive(nums);
}