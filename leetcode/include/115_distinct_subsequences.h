#include <string>
#include <vector>

using namespace std;

struct vector_slice {
    vector<int> data;
    int start;
    vector_slice(vector<int> &data, int start): data(data), start(start) {}
};

class DistinctSubsequencesSolution {
public:
    vector<vector_slice> build_index(string &s, string &t);
    void count_subsequences(vector<vector_slice> &index, int pos, int *count);
    int find_start(int idx, vector_slice &slice);
    int num_distinct_naive_index(string s, string t);

    int count_recursive_naive(string s, string t);
    int count_memo(string &s, string &t, int pos_s, int pos_t);

    int numDistinct(string s, string t);
};