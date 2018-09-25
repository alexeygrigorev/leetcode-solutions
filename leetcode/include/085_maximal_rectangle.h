#include <vector>
#include <unordered_set>

using namespace std;

struct coord {
    int row;
    int col;

    coord(int row, int col): row(row), col(col) {}

    coord inc_row() {
        return coord(row + 1, col);
    }

    coord inc_col() {
        return coord(row, col + 1);
    }
};

struct rectangle {
    coord start;
    coord end;

    rectangle(coord start, coord end): start(start), end(end) {}

    int calculate_area() {
        int h = end.row - start.row + 1;
        int w = end.col - start.col + 1;
        return h * w;
    }

    bool operator ==(const rectangle &other) const {
        return start.row == other.start.row &&
               start.col == other.start.col &&
               end.row == other.end.row &&
               end.col == other.end.col;
    }
};

struct rectangle_hash {
    size_t operator() (const rectangle &rect) const {
        size_t hash = 1;
        hash = 31 * hash + rect.start.row;
        hash = 31 * hash + rect.start.col;
        hash = 31 * hash + rect.end.row;
        hash = 31 * hash + rect.end.col;
        return hash;
    }

};

class MaximalRectangleNaiveSolution {
public:
    bool can_expand_right(vector<vector<char>> &matrix, coord &start, coord &current);
    bool can_expand_bottom(vector<vector<char>> &matrix, coord &start, coord &current);
    int calculate_area(coord &start, coord &end);
    coord grow_recursive(vector<vector<char>> &matrix, coord start, coord current);
    int maximalRectangle(vector<vector<char>> &matrix);
};

class MaximalRectangleDfsSolution {
public:
    bool can_expand_row(vector<vector<char>> &matrix, int row, int col_start, int col_end);
    bool can_expand_col(vector<vector<char>> &matrix, int col, int row_start, int row_end);

    bool can_expand_left(vector<vector<char>> &matrix, rectangle &rect);
    bool can_expand_right(vector<vector<char>> &matrix, rectangle &rect);
    bool can_expand_up(vector<vector<char>> &matrix, rectangle &rect);
    bool can_expand_down(vector<vector<char>> &matrix, rectangle &rect);

    void grow_recursive(vector<vector<char>> &matrix, rectangle &rect,
                        vector<rectangle> &rectangles,
                        unordered_set<rectangle, rectangle_hash> &visited);

    int maximalRectangle(vector<vector<char>> &matrix);
};