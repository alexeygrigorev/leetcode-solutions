#include <string>
#include <vector>

using namespace std;

class DistinctSubsequencesSolution {
public:
    int count_recursive_naive(string s, string t);
    int count_memo(string &s, string &t, int pos_s, int pos_t, vector<vector<int>> &memo);

    int num_distinct_memo(string &s, string &t);
    int num_distinct_dp(string &s, string &t);

    int numDistinct(string s, string t);
};