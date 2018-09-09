#include "240_search_2d_matrix_2.h"

bool Search2DMatrix2Solution::binary_search_2d(vector<vector<int>> &matrix, int target, int row_start, int row_end,
                                               int col_start, int col_end) {
    if (row_start >= row_end || col_start >= col_end) {
        return false;
    }

    int row_mid = row_start + (row_end - 1 - row_start) / 2;
    int col_mid = col_start + (col_end - 1 - col_start) / 2;

    int el = matrix[row_mid][col_mid];
    if (el == target) {
        return true;
    }

    int size = (row_end - row_start) * (col_end - col_start);
    if (size == 1) {
        return false;
    }

    if (target < el) {
        return
            binary_search_2d(matrix, target, row_start, row_mid + 1, col_start, col_mid + 1) ||
            binary_search_2d(matrix, target, row_start, row_mid + 1, col_mid + 1, col_end) ||
            binary_search_2d(matrix, target, row_mid + 1, row_end, col_start, col_mid + 1);
    } else {
        return
            binary_search_2d(matrix, target, row_start, row_mid + 1, col_mid + 1, col_end) ||
            binary_search_2d(matrix, target, row_mid + 1, row_end, col_start, col_mid + 1) ||
            binary_search_2d(matrix, target, row_mid + 1, row_end, col_mid + 1, col_end);
    }
}

bool Search2DMatrix2Solution::search_matrix_naive(vector<vector<int>> &matrix, int target) {
     if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    return binary_search_2d(matrix, target, 0, matrix.size(), 0, matrix[0].size());
}

bool Search2DMatrix2Solution::searchMatrix(vector<vector<int>> &matrix, int target) {
    return search_matrix_naive(matrix, target);
}
