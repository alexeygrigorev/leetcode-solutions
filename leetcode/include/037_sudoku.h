#include <vector>

using namespace std;

struct Candidates {
    int row, col;

    int num_candidates;
    vector<bool> candidates;
    bool visited;

    vector<Candidates*> others;
};

struct CandidatesCompare {
    bool operator() (const Candidates *c1, const Candidates *c2) const {
        return c1->num_candidates < c2->num_candidates;
    }
};

class SudokuSolution {
public:
    void find_candidates(vector<vector<char>> &board,
                         vector<vector<Candidates *>> &idx,
                         Candidates *C);
    Candidates* min_candidate(vector<Candidates*> &idx);
    vector<Candidates*> remove_candidates(Candidates* meta, int candidate);
    void return_candidates(vector<Candidates*> &coords, int candidate);
    bool solve(vector<vector<char>> &board, vector<Candidates*> &idx, int l);

    vector<Candidates*> build_index(vector<vector<char>> &board);

    bool cannot_remove_candidate(Candidates *c, int candidate);

    void solveSudoku(vector<vector<char>> &board);
};