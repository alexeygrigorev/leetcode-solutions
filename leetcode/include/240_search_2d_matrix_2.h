#include <vector>

using namespace std;

class Search2DMatrix2Solution {
    bool binary_search_2d(vector<vector<int>> &matrix, int target,
            int row_start, int row_end, int col_start, int col_end);
    bool search_matrix_naive(vector<vector<int>> &matrix, int target);
    bool searchMatrix(vector<vector<int>> &matrix, int target);
};