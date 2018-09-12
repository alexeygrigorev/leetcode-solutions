#include <vector>
#include <string>

using namespace std;

class SubstringConcatSolution {
public:
    int total_length(vector<string> &words);
    pair<vector<string>, vector<int>> unique(vector<string> &words);
    vector<vector<int>> calculate_matches(string &s, vector<string> &words);
    vector<int> find_matches(vector<vector<int>> &matches, vector<int> &lens,
                             vector<int> &counts);
    bool match(int start, vector<vector<int>> &matches, vector<int> &lens,
                                    vector<int> &counts, int num_used);

    vector<int> findSubstring(string s, vector<string> &words);
};
