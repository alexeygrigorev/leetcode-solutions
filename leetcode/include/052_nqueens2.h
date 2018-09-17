#include <vector>

using namespace std;

#define EMPTY 0
#define TAKEN 1
#define QUEEN 2

class NQueens2Solution {
public:
    void fill_mask(int row, int col, vector<vector<int>> &mask);
    void solve(int row, vector<vector<int>> &mask, int *count);
    int totalNQueens(int n);
};
