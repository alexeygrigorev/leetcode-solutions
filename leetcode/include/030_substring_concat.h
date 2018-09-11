#include <vector>
#include <string>

using namespace std;

class SubstringConcatSolution {
public:
    bool match(string &s, int start, vector<string> &words, vector<bool> &used,
               int words_used);
    vector<int> findSubstring(string s, vector<string> &words);
};
