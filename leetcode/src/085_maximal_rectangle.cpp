#include "085_maximal_rectangle.h"

bool MaximalRectangleNaiveSolution::can_expand_right(vector<vector<char>> &matrix, coord &start, coord &current) {
    int num_cols = matrix[0].size();

    int new_col = current.col + 1;
    if (new_col >= num_cols) {
        return false;
    }

    for (int row = start.row; row <= current.row; row++) {
        if (matrix[row][new_col] != '1') {
            return false;
        }
    }

    return true;
}

bool MaximalRectangleNaiveSolution::can_expand_bottom(vector<vector<char>> &matrix, coord &start, coord &current) {
    int num_rows = matrix.size();

    int new_row = current.row + 1;
    if (new_row >= num_rows) {
        return false;
    }

    for (int col = start.col; col <= current.col; col++) {
        if (matrix[new_row][col] != '1') {
            return false;
        }
    }

    return true;
}

int MaximalRectangleNaiveSolution::calculate_area(coord &start, coord &end) {
    int h = end.row - start.row + 1;
    int w = end.col - start.col + 1;
    return h * w;
}

coord MaximalRectangleNaiveSolution::grow_recursive(vector<vector<char>> &matrix, coord start, coord current) {
    // int area_so_far = calculate_area(start, current);
    // printf("run from %d-%d to %d-%d, area=%d\n", start.row, start.col, current.row, current.col, area_so_far);
    bool right = can_expand_right(matrix, start, current);
    bool bottom = can_expand_bottom(matrix, start, current);
    // printf(" - expand to right? %d; expand to bottom? %d\n", right, bottom);

    if (!right && !bottom) {
        return current;
    }

    // coord *go_right = nullptr;
    // coord *go_bottom = nullptr;
    // coord *go_both = nullptr;

    vector<coord> results;

    if (right) {
        coord go_right = grow_recursive(matrix, start, current.inc_col());
        results.push_back(go_right);
    }

    if (bottom) {
        coord go_bottom = grow_recursive(matrix, start, current.inc_row());
        results.push_back(go_bottom);
    }

    if (right && bottom) {
        coord new_coord = coord(current.row + 1, current.col + 1);
        if (matrix[new_coord.row][new_coord.col] == '1') {
            coord go_both = grow_recursive(matrix, start, new_coord);
            results.push_back(go_both);
        }
    }

    int max_area = calculate_area(start, results[0]);
    coord best = results[0];

    for (int i = 1; i < results.size(); i++) {
        int area = calculate_area(start, results[i]);
        if (area > max_area) {
            best = results[i];
            max_area = area;
        }
    }

    return best;
}

int MaximalRectangleNaiveSolution::maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int num_rows = matrix.size();
    int num_cols = matrix[0].size();

    int max_area = 0;

    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            int possible_area = (num_rows - row) * (num_cols - col);
            if (possible_area <= max_area) {
                break;
            }

            if (matrix[row][col] == '1') {
                coord start(row, col);
                coord best = grow_recursive(matrix, start, start);
                int area = calculate_area(start, best);
                // printf("for %d,%d => %d,%d max area is %d\n", start.row, start.col, best.row, best.col, area);
                max_area = max(area, max_area);
            }
        }
    }

    return max_area;
}
