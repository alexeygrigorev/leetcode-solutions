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
    bool right = can_expand_right(matrix, start, current);
    bool bottom = can_expand_bottom(matrix, start, current);

    if (!right && !bottom) {
        return current;
    }

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
                max_area = max(area, max_area);
            }
        }
    }

    return max_area;
}


bool MaximalRectangleDfsSolution::can_expand_row(vector<vector<char>> &matrix, int row, int col_start, int col_end) {
    if (row < 0 || row >= matrix.size()) {
        return false;
    }

    for (int col = col_start; col <= col_end; col++) {
        if (matrix[row][col] != '1') {
            return false;
        }
    }

    return true;

}

bool MaximalRectangleDfsSolution::can_expand_col(vector<vector<char>> &matrix, int col, int row_start, int row_end) {
    if (col < 0 || col >= matrix[0].size()) {
        return false;
    }

    for (int row = row_start; row <= row_end; row++) {
        if (matrix[row][col] != '1') {
            return false;
        }
    }

    return true;
}

bool MaximalRectangleDfsSolution::can_expand_right(vector<vector<char>> &matrix,
                                                   rectangle &rect) {
    return can_expand_col(matrix, rect.end.col + 1, rect.start.row, rect.end.row);
}

bool MaximalRectangleDfsSolution::can_expand_up(vector<vector<char>> &matrix,
                                                rectangle &rect) {
    return can_expand_row(matrix, rect.start.row - 1, rect.start.col, rect.end.col);
}

bool MaximalRectangleDfsSolution::can_expand_down(vector<vector<char>> &matrix,
                                                  rectangle &rect) {
    return can_expand_row(matrix, rect.end.row + 1, rect.start.col, rect.end.col);
}

bool MaximalRectangleDfsSolution::can_expand_left(vector<vector<char>> &matrix,
                                                  rectangle &rect) {
    return can_expand_col(matrix, rect.start.col - 1, rect.start.row, rect.end.row);
}

void MaximalRectangleDfsSolution::grow_recursive(vector<vector<char>> &matrix,
         rectangle &rect, vector<rectangle> &rectangles,
         unordered_set<rectangle, rectangle_hash> &visited) {

    coord start = rect.start;
    coord end = rect.end;

    rectangle up_rect(coord(start.row - 1, start.col), end);
    bool not_visited_up = visited.count(up_rect) == 0;
    bool up = not_visited_up && can_expand_up(matrix, rect);
    if (up) {
        grow_recursive(matrix, up_rect, rectangles, visited);
    }

    rectangle down_rect(start, coord(end.row + 1, end.col));
    bool not_visited_down = visited.count(down_rect) == 0;
    bool down = not_visited_down && can_expand_down(matrix, rect);
    if (down) {
        grow_recursive(matrix, down_rect, rectangles, visited);
    }

    rectangle left_rect(coord(start.row, start.col - 1), end);
    bool not_visited_left = visited.count(left_rect) == 0;
    bool left = not_visited_left && can_expand_left(matrix, rect);
    if (left) {
        grow_recursive(matrix, left_rect, rectangles, visited);
    }

    rectangle right_rect(start, coord(end.row, end.col + 1));
    bool not_visited_right = visited.count(right_rect) == 0;
    bool right = not_visited_right && can_expand_right(matrix, rect);
    if (right) {
        grow_recursive(matrix, right_rect, rectangles, visited);
    }

    if (!(up || down || left || right)) {
        rectangles.push_back(rect);
    }

    visited.insert(rect);
}

int MaximalRectangleDfsSolution::maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int num_rows = matrix.size();
    int num_cols = matrix[0].size();

    vector<vector<bool>> assigned(num_rows, vector<bool>(num_cols, false));

    int max_area = 0;

    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            if (matrix[row][col] != '1' || assigned[row][col]) {
                continue;
            }

            rectangle rect(coord(row, col), coord(row, col));

            vector<rectangle> rectangles;
            unordered_set<rectangle, rectangle_hash> visited;
            visited.insert(rect);

            grow_recursive(matrix, rect, rectangles, visited);

            for (rectangle &r : rectangles) {
                max_area = max(max_area, r.calculate_area());

                for (int i = r.start.row; i <= r.end.row; i++) {
                    for (int j = r.start.col; j <= r.end.col; j++) {
                        assigned[i][j] = true;
                    }
                }
            }
        }
    }

    return max_area;
}

int MaximalRectangleOptimalSolution::maximal_rectangle_stack(vector<vector<char>> &matrix) {
    return 0;
}

int MaximalRectangleOptimalSolution::maximal_rectangle_dp(vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int num_rows = matrix.size();
    int num_cols = matrix[0].size();

    vector<vector<int>> height(num_rows + 1, vector<int>(num_cols));
    vector<vector<int>> left(num_rows + 1, vector<int>(num_cols));
    vector<vector<int>> right(num_rows + 1, vector<int>(num_cols, num_cols));

    int max_area = 0;

    for (int row = 0; row < num_rows; row++) {

        for (int col = 0; col < num_cols; col++) {
            if (matrix[row][col] == '1') {
                height[row + 1][col] = height[row][col] + 1;
            }
        }

        int left_start = 0;
        for (int col = 0; col < num_cols; col++) {
            if (matrix[row][col] == '1') {
                left[row + 1][col] = max(left[row][col], left_start);
            } else {
                left_start = col + 1;
            }
        }

        int right_end = num_cols - 1;
        for (int col = num_cols - 1; col >= 0; col--) {
            if (matrix[row][col] == '1') {
                right[row + 1][col] = min(right[row][col], right_end);
            } else {
                right_end = col - 1;
            }
        }

        for (int col = 0; col < num_cols; col++) {
            if (matrix[row][col] != '1') {
                continue;
            }

            int h = height[row + 1][col];
            int start = left[row + 1][col];
            int end = right[row + 1][col];
            int w = end - start + 1;
            int area = h * w;

            max_area = max(area, max_area);
        }

    }

    return max_area;
}

int MaximalRectangleOptimalSolution::maximalRectangle(vector<vector<char>> &matrix) {
    return maximal_rectangle_dp(matrix);
}
