#include "238_self_product.h"

vector<int> SelfProductSolution::product_except_self_two_arrays(vector<int> &nums) {
    // idea:
    // suppose n = 4:
    // o[0] =   1  * v[1] * v[2] * v[3]
    // o[1] = v[0] *   1  * v[2] * v[3]
    // o[2] = v[0] * v[1] *   1  * v[3]
    // o[3] = v[0] * v[1] * v[2] *   1
    // we can split it into two parts:
    // o1[0] =   1
    // o1[1] = v[0]
    // o1[2] = v[0] * v[1]
    // o1[3] = v[0] * v[1] * v[2]
    // and
    // o2[0] =        v[1] * v[2] * v[3]
    // o2[1] =               v[2] * v[3]
    // o2[2] =                      v[3]
    // o2[3] =                        1
    // computing o1 and o2 in one pass is trivial
    // then o[i] = o1[i] * o2[i]

    int n = nums.size();
    vector<int> out1(n, 1);
    vector<int> out2(n, 1);

    for (int i = 1; i < n; i++) {
        out1[i] = out1[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        out2[i] = out2[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; i++) {
        out1[i] = out1[i] * out2[i];
    }

    return out1;
}

vector<int> SelfProductSolution::product_except_self_o1_memory(vector<int> &nums) {
    // idea is same as previously, but we actually don't need two arrays
    // to store the growing product
    int n = nums.size();
    vector<int> out(n, 1);

    int tmp1 = 1;
    for (int i = 1; i < n; i++) {
        tmp1 = tmp1 * nums[i - 1];
        out[i] = tmp1; // out[i] * tmp1
    }

    int tmp2 = 1;
    for (int i = n - 2; i >= 0; i--) {
        tmp2 = tmp2 * nums[i + 1];
        out[i] = out[i] * tmp2;
    }

    return out;
}

vector<int> SelfProductSolution::product_except_self_one_pass(vector<int> &nums) {
    // idea is the same as previously,
    // we just don't need to do two passes -
    // it's enough to compute the other index as we go
    int n = nums.size();
    vector<int> out(n, 1);

    int tmp1 = 1;
    int tmp2 = 1;

    for (int i = 1; i < n; i++) {
        tmp1 = tmp1 * nums[i - 1];
        out[i] = out[i] * tmp1;

        int j = n - i - 1;
        tmp2 = tmp2 * nums[j + 1];
        out[j] = out[j] * tmp2;
    }

    return out;
}


vector<int> SelfProductSolution::productExceptSelf(vector<int> &nums) {
    return product_except_self_one_pass(nums);
}

