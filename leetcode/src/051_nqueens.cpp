#include "051_nqueens.h"

void NQueensSolution::fill_mask(int row, int col, vector<vector<int>> &mask) {
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

vector<string> NQueensSolution::from_mask(vector<vector<int>> &mask) {
    int n = mask.size();
    vector<string> result(n, string(n, '.'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mask[i][j] == QUEEN) {
                result[i][j] = 'Q';
            }
        }
    }

    return result;
}

void NQueensSolution::solve(int row, vector<vector<int>> &mask, vector<vector<string>> &solutions) {
    int n = mask.size();

    if (row == n) {
        vector<string> board = from_mask(mask);
        solutions.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++) {
        if (mask[row][c] == EMPTY) {
            vector<vector<int>> copy = mask;
            fill_mask(row, c, copy);
            solve(row + 1, copy, solutions);
        }
    }
}

vector<vector<string>> NQueensSolution::solveNQueens(int n) {
    vector<vector<int>> mask(n, vector<int>(n, EMPTY));
    vector<vector<string>> solutions;
    solve(0, mask, solutions);
    return solutions;
}
