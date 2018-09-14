#include "036_valid_sudoku.h"

bool ValidSudokuSolution::isValidSudoku(vector<vector<char>> &board) {
    // check rows
    for (int row = 0; row < 9; row++) {
        vector<bool> used(9, false);
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                continue;
            }
            int pos = board[row][col] - '1';
            if (used[pos] == true) {
                return false;
            }
            used[pos] = true;
        }
    }

    // check cols
    for (int col = 0; col < 9; col++) {
        vector<bool> used(9, false);
        for (int row = 0; row < 9; row++) {
            if (board[row][col] == '.') {
                continue;
            }
            int pos = board[row][col] - '1';
            if (used[pos] == true) {
                return false;
            }
            used[pos] = true;
        }
    }

    // check squares
    for (int col = 0; col < 9; col = col + 3) {
        for (int row = 0; row < 9; row = row + 3) {
            vector<bool> used(9, false);

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[row + i][col + j] == '.') {
                        continue;
                    }
                    int pos = board[row + i][col + j] - '1';
                    if (used[pos] == true) {
                        return false;
                    }
                    used[pos] = true;
                }
            }
        }
    }

    return true;
}
