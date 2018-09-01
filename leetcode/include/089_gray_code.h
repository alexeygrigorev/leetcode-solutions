#include <vector>

using namespace std;

class GrayCodeSolution {
public:
    vector<int> gray_code_iterative(int n);

    void backtrack(int k, int *bits, vector<int> &result);
    vector<int> gray_code_backtrack(int n);

    vector<int> grayCode(int n);
};