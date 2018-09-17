#include <vector>
#include <string>

using namespace std;

#define EMPTY 0
#define TAKEN 1
#define QUEEN 2

class NQueensSolution {
public:
    void fill_mask(int row, int col, vector<vector<int>> &mask);
    vector<string> from_mask(vector<vector<int>> &mask);
    void solve(int row, vector<vector<int>> &mask, vector<vector<string>> &solutions);
    vector<vector<string>> solveNQueens(int n);
};
