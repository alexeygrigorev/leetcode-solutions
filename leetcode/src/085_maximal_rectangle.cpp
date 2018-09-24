#include <cstdio>
#include <unordered_set>
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

void MaximalRectangleDfsSolution::grow_recursive(vector<vector<char>> &matrix,
         rectangle &rect, vector<rectangle> &rectangles,
         unordered_set<rectangle, rectangle_hash> &visited) {

    coord start = rect.start;
    coord end = rect.end;

    rectangle up_rect(coord(start.row - 1, start.col), end);
    rectangle down_rect(start, coord(end.row + 1, end.col));
    rectangle left_rect(coord(start.row, start.col - 1), end);
    rectangle right_rect(start, coord(end.row, end.col + 1));

    bool not_visited_up = visited.count(up_rect) == 0;
    bool up = not_visited_up && can_expand_up(matrix, rect);
//    printf("can expand (%d,%d)->(%d,%d) up? %d %d\n", start.row, start.col, end.row, end.col, not_visited_up, up);
    if (up) {
        grow_recursive(matrix, up_rect, rectangles, visited);
    }

    bool not_visited_down = visited.count(down_rect) == 0;
    bool down = not_visited_down && can_expand_down(matrix, rect);
//    printf("can expand (%d,%d)->(%d,%d) down? %d %d\n", start.row, start.col, end.row, end.col, not_visited_down, down);
    if (down) {
        grow_recursive(matrix, down_rect, rectangles, visited);
    }

    bool not_visited_left = visited.count(left_rect) == 0;
    bool left = not_visited_left && can_expand_left(matrix, rect);
//    printf("can expand (%d,%d)->(%d,%d) left? %d, %d\n", start.row, start.col, end.row, end.col, not_visited_left, left);
    if (left) {
        grow_recursive(matrix, left_rect, rectangles, visited);
    }

    bool not_visited_right = visited.count(right_rect) == 0;
    bool right = not_visited_right && can_expand_right(matrix, rect);
//    printf("can expand (%d,%d)->(%d,%d) right? %d, %d\n", start.row, start.col, end.row, end.col, not_visited_right, right);
    if (right) {
        grow_recursive(matrix, right_rect, rectangles, visited);
    }

    if (!(up || down || left || right)) {
//        printf("can no longer expand (%d,%d)->(%d,%d)\n", start.row, start.col, end.row, end.col);
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

    vector<rectangle> all_rectangles;
    vector<vector<bool>> assigned(num_rows, vector<bool>(num_cols, false));

    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            if (matrix[row][col] != '1' || assigned[row][col]) {
                continue;
            }

//            printf("run search from %d,%d\n", row, col);

            rectangle rect(coord(row, col), coord(row, col));

            vector<rectangle> rectangles;
            unordered_set<rectangle, rectangle_hash> visited;
            visited.insert(rect);

            grow_recursive(matrix, rect, rectangles, visited);

            for (rectangle &r : rectangles) {
//                int area = r.calculate_area();
//                printf("found a rectangle (%d,%d) -> (%d,%d), area %d\n",
//                       r.start.row, r.start.col,
//                       r.end.row, r.end.col, area);

                all_rectangles.push_back(r);

                coord start = r.start;
                coord end = r.end;

                for (int i = start.row; i <= end.row; i++) {
                    for (int j = start.col; j <= end.col; j++) {
                        assigned[i][j] = true;
                    }
                }
            }
        }
    }

    if (all_rectangles.empty()) {
        return 0;
    }


    int max_area = all_rectangles[0].calculate_area();

    for (int i = 1; i < all_rectangles.size(); i++) {
        int area = all_rectangles[i].calculate_area();
        max_area = max(area, max_area);
    }

    return max_area;
}

bool MaximalRectangleDfsSolution::can_expand_right(vector<vector<char>> &matrix,
                                                   rectangle &rect) {
    int num_cols = matrix[0].size();

    coord start = rect.start;
    coord end = rect.end;

    int new_col = end.col + 1;
    if (new_col >= num_cols) {
        return false;
    }

    for (int row = start.row; row <= end.row; row++) {
        if (matrix[row][new_col] != '1') {
            return false;
        }
    }

    return true;
}

bool MaximalRectangleDfsSolution::can_expand_up(vector<vector<char>> &matrix,
                                                rectangle &rect) {
    coord start = rect.start;
    coord end = rect.end;

    if (start.row == 0) {
        return false;
    }

    int new_row = start.row - 1;

    for (int col = start.col; col <= end.col; col++) {
        if (matrix[new_row][col] != '1') {
            return false;
        }
    }

    return true;
}

bool MaximalRectangleDfsSolution::can_expand_down(vector<vector<char>> &matrix,
                                                  rectangle &rect) {
    int num_rows = matrix.size();
    coord start = rect.start;
    coord end = rect.end;

    int new_row = end.row + 1;
    if (new_row >= num_rows) {
        return false;
    }

    for (int col = start.col; col <= end.col; col++) {
        if (matrix[new_row][col] != '1') {
            return false;
        }
    }

    return true;
}

bool MaximalRectangleDfsSolution::can_expand_left(vector<vector<char>> &matrix,
                                                  rectangle &rect) {
    coord start = rect.start;
    coord end = rect.end;

    if (start.col == 0) {
        return false;
    }

    int new_col = start.col - 1;

    for (int row = start.row; row <= end.row; row++) {
        if (matrix[row][new_col] != '1') {
            return false;
        }
    }

    return true;
}
