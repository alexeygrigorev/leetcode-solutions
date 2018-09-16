#include "037_sudoku.h"
#include <algorithm>

void
SudokuSolution::find_candidates(vector<vector<char>> &board,
                                vector<vector<Candidates *>> &idx,
                                Candidates *c) {
    vector<vector<bool>> used(9, vector<bool>(9, false));
    int row = c->row;
    int col = c->col;
    used[row][col] = true;

    for (int j = 0; j < 9; j++) {
        char ch = board[row][j];
        if (ch != '.') {
            int pos = ch - '1';
            if (c->candidates[pos]) {
                c->candidates[pos] = false;
                c->num_candidates--;
            }
        } else if (used[row][j] == false) {
            c->others.push_back(idx[row][j]);
            used[row][j] = true;
        }
    }

    for (int i = 0; i < 9; i++) {
        char ch = board[i][col];
        if (ch != '.') {
            int pos = ch - '1';
            if (c->candidates[pos]) {
                c->candidates[pos] = false;
                c->num_candidates--;
            }
        } else if (used[i][col] == false) {
            c->others.push_back(idx[i][col]);
            used[i][col] = true;
        }
    }

    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;

    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            char ch = board[i][j];
            if (ch != '.') {
                int pos = ch - '1';
                if (c->candidates[pos]) {
                    c->candidates[pos] = false;
                    c->num_candidates--;
                }
            } else if (used[i][j] == false) {
                c->others.push_back(idx[i][j]);
                used[i][j] = true;
            }
        }
    }
}

Candidates* SudokuSolution::min_candidate(vector<Candidates*> &idx) {
    int min = 9;
    Candidates* result = nullptr;

    for (Candidates *c : idx) {
        if (c != nullptr && !c->visited) {
            if (c->num_candidates < min) {
                min = c->num_candidates;
                result = c;
            }
        }
    }

    return result;
}

vector<Candidates*>
SudokuSolution::remove_candidates(Candidates *meta, int candidate) {
    vector<Candidates*> coords;

    for (Candidates *other : meta->others) {
        if (other->candidates[candidate] == true) {
            other->candidates[candidate] = false;
            other->num_candidates--;
            coords.push_back(other);
        }
    }

    return coords;
}

void
SudokuSolution::return_candidates(vector<Candidates*> &coords, int candidate) {
    for (auto other : coords) {
        other->candidates[candidate] = true;
        other->num_candidates++;
    }
}

bool SudokuSolution::solve(vector<vector<char>> &board, vector<Candidates*> &idx, int l) {
    Candidates* c = min_candidate(idx);
    if (c == nullptr) {
        return true;
    }

    for (int i = 0; i < 9; i++) {
        if (c->candidates[i] == false) {
            continue;
        }

        if (cannot_remove_candidate(c, i)) {
            continue;
        }

        c->candidates[i] = false;
        c->num_candidates--;
        c->visited = true;

        vector<Candidates*> coords = remove_candidates(c, i);

        board[c->row][c->col] = i + '1';
        if (solve(board, idx, l + 1)) {
            return true;
        }

        board[c->row][c->col] = '.';
        return_candidates(coords, i);

        c->candidates[i] = true;
        c->num_candidates++;
        c->visited = false;
    }

    return false;
}

vector<Candidates*> SudokuSolution::build_index(vector<vector<char>> &board) {
    vector<vector<Candidates*>> idx(9, vector<Candidates*>(9, nullptr));
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] != '.') {
                continue;
            }

            Candidates *result = new Candidates();
            result->row = row;
            result->col = col;
            result->candidates = vector<bool>(9, true);
            result->num_candidates = 9;
            result->visited = false;
            result->others = vector<Candidates*>();

            idx[row][col] = result;
        }
    }

    vector<Candidates*> result;

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] != '.') {
                continue;
            }

            find_candidates(board, idx, idx[row][col]);
            result.push_back(idx[row][col]);
        }
    }

    return result;
}

bool SudokuSolution::cannot_remove_candidate(Candidates *c, int candidate) {
    for (Candidates *other : c->others) {
        if (other->visited == true) {
            continue;
        }

        if (other->candidates[candidate] == true && other->num_candidates == 1) {
            return true;
        }
    }

    return false;
}

void SudokuSolution::solveSudoku(vector<vector<char>> &board) {
    vector<Candidates*> idx = build_index(board);
    solve(board, idx, 0);
}
