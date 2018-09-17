#include "052_nqueens2.h"

void NQueens2Solution::fill_mask(int row, int col, vector<vector<int>> &mask) {
    int n = mask.size();

    for (int i = 0; i < n; i++) {
        mask[row][i] = TAKEN;
        mask[i][col] = TAKEN;

        int diag_i = (col - row) + i;
        if (diag_i >= 0 && diag_i < n) {
            mask[i][diag_i] = TAKEN;
        }

        int odiag_i = (row + col) - i;
        if (odiag_i >= 0 && odiag_i < n) {
            mask[i][odiag_i] = TAKEN;
        }
    }

    mask[row][col] = QUEEN;
}

void NQueens2Solution::solve(int row, vector<vector<int>> &mask, int *count) {
    int n = mask.size();

    if (row == n) {
        *count = *count + 1;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (mask[row][c] == EMPTY) {
            vector<vector<int>> copy = mask;
            fill_mask(row, c, copy);
            solve(row + 1, copy, count);
        }
    }
}

int NQueens2Solution::totalNQueens(int n) {
    vector<vector<int>> mask(n, vector<int>(n, EMPTY));
    int count = 0;
    solve(0, mask, &count);
    return count;
}

