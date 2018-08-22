#include <vector>
using namespace std;

class RotateImageSolution {
public:
    void transpose(vector<vector<int>>& m);
    void reverse_rows(vector<vector<int>>& m);
    void rotate_transpose_reverse(vector<vector<int>> &m);
    void rotate_blocks(vector<vector<int>>& m);
    void rotate(vector<vector<int>>& m);
};