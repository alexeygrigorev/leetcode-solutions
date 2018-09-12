#include <vector>
#include <string>

using namespace std;

class SubstringConcatSolution {
public:
    vector<int> findSubstring(string s, vector<string> &words);

    vector<vector<int>> calculate_matches(const string &s, const vector<string> &words) const;

    vector<int> find_matches(vector<vector<int>> &matches, vector<int> &lens,
                             vector<int> &counts);

    bool match(int start, vector<vector<int>> &matches, vector<int> &lens,
                                    vector<int> &counts, int num_used);

    pair<vector<string>, vector<int>> unique(vector<string> &words);
};
