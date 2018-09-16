#include <vector>

using namespace std;

struct Candidates {
    int row, col;

    int num_candidates;
    vector<bool> candidates;
    bool visited;

    vector<Candidates*> others;
};

class SudokuSolution {
public:
    vector<Candidates*> build_index(vector<vector<char>> &board);
    void find_candidates(vector<vector<char>> &board,
        vector<vector<Candidates *>> &idx,  Candidates *C);

    bool solve(vector<vector<char>> &board, vector<Candidates*> &idx);
    Candidates* min_candidate(vector<Candidates*> &idx);
    bool cannot_remove_candidate(Candidates *c, int candidate);
    vector<Candidates*> remove_candidates(Candidates* meta, int candidate);
    void return_candidates(vector<Candidates*> &coords, int candidate);

    void solveSudoku(vector<vector<char>> &board);
};