#include <vector>
#include <string>

using namespace std;

struct StringLenCompare {
    bool operator()(const string &first, const string &second) const {
        return first.size() > second.size();
    }
};

class WordBreakSolution {
public:
    bool word_break_helper(string &s, int start, vector<vector<string>> &dict,
                           vector<bool> &visited);
    bool wordBreak(string s, vector<string> &wordDict);
};