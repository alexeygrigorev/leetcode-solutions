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

vector<int> GrayCodeSolution::grayCode(int n) {
    return gray_code_iterative(n);
}
