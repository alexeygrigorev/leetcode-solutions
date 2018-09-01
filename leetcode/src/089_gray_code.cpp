#include "089_gray_code.h"

vector<int> GrayCodeSolution::gray_code_iterative(int n) {
    vector<int> result = {0};

    for (int i = 0; i < n; i++) {
        int curr_size = result.size();
        for (int k = curr_size - 1; k >= 0; k--) {
            int g = result[k];
            g = g | (1 << i);
            result.push_back(g);
        }
    }

    return result;
}

void GrayCodeSolution::backtrack(int k, int *bits, vector<int> &result) {
    if (k == 0) {
        result.push_back(*bits);
        return;
    }

    backtrack(k - 1, bits, result);
    *bits = *bits ^ (1 << (k - 1));
    backtrack(k - 1, bits, result);
}

vector<int> GrayCodeSolution::gray_code_backtrack(int n) {
    // from https://leetcode.com/problems/gray-code/discuss/29880
    int bits = 0;
    vector<int> result;
    backtrack(n, &bits, result);
    return result;
}

vector<int> GrayCodeSolution::grayCode(int n) {
    return gray_code_iterative(n);
}
