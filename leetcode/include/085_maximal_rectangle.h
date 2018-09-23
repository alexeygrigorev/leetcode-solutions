#include <vector>

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

class MaximalRectangleNaiveSolution {
    bool can_expand_right(vector<vector<char>> &matrix, coord &start, coord &current);
    bool can_expand_bottom(vector<vector<char>> &matrix, coord &start, coord &current);
    int calculate_area(coord &start, coord &end);
    coord grow_recursive(vector<vector<char>> &matrix, coord start, coord current);
    int maximalRectangle(vector<vector<char>> &matrix);
};