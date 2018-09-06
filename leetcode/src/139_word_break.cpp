#include "139_word_break.h"
#include <algorithm>

bool WordBreakSolution::word_break_helper(string &s, int start,
                                          vector<vector<string>> &dict, vector<bool> &visited) {
    int n = s.length();

    if (start >= n) {
        return true;
    }

    int index = s[start] - 'a';

    for (string w : dict[index]) {
        int len = w.length();
        if (len > n) {
            continue;
        }

        if (visited[start + len]) {
            continue;
        }

        if (s.substr(start, len) == w) {
            if (word_break_helper(s, start + len, dict, visited)) {
                visited[start + len] = true;
                return true;
            }
        }
    }

    visited[start] = true;
    return false;
}

bool WordBreakSolution::wordBreak(string s, vector<string> &wordDict) {
    if (wordDict.empty()) {
        return false;
    }

    StringLenCompare comparator;
    sort(wordDict.begin(), wordDict.end(), comparator);

    int size = 'z' - 'a';
    vector<vector<string>> dict(size);

    for (string w : wordDict) {
        dict[w[0] - 'a'].push_back(w);
    }

    vector<bool> visited(s.length(), false);

    return word_break_helper(s, 0, dict, visited);
}
