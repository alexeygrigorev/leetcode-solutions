#include "030_substring_concat.h"
#include <unordered_set>
#include <unordered_map>

int SubstringConcatSolution::total_length(vector<string> &words) {
    int total_len = 0;
    for (const string &word : words) {
        int len = word.length();
        total_len = total_len + len;
    }
    return total_len;
}

pair<vector<string>, vector<int>> SubstringConcatSolution::unique(vector<string> &words) {
    unordered_map<string, int> counter;

    for (const string &w : words) {
        counter[w]++;
    }

    vector<string> unique;
    vector<int> counts;

    for (auto pair : counter) {
        unique.push_back(pair.first);
        counts.push_back(pair.second);
    }

    return { unique, counts };
}

vector<vector<int>> SubstringConcatSolution::calculate_matches(string &s, vector<string> &words) {
    int num_words = words.size();

    vector<vector<int>> matches;

    int n = s.length();

    for (int i = 0; i < n; i++) {
        vector<int> match;
        for (int j = 0; j < num_words; j++) {
            string word = words[j];
            int len = word.length();
            if (i + len > n) {
                continue;
            }

            if (word[0] != s[i]) {
                continue;
            }

            string sub = s.substr(i, len);
            if (sub == word) {
                match.push_back(j);
            }
        }

        matches.push_back(match);
    }

    return matches;
}

vector<int> SubstringConcatSolution::find_matches(vector<vector<int>> &matches,
                                                  vector<int> &lens,
                                                  vector<int> &counts) {
    int total_len = 0;
    int total_cnt = 0;
    for (int i = 0; i < lens.size(); i++) {
        total_len = total_len + lens[i] * counts[i];
        total_cnt = total_cnt + counts[i];
    }

    int n = matches.size();

    vector<int> result;

    for (int i = 0; i < n - total_len + 1; i++) {
        if (matches[i].empty()) {
            continue;
        }

        vector<int> counts_copy = counts;

        if (match(i, matches, lens, counts_copy, total_cnt)) {
            result.push_back(i);
        }
    }

    return result;
}

bool SubstringConcatSolution::match(int start, vector<vector<int>> &matches,
                                    vector<int> &lens,
                                    vector<int> &counts, int num_remaining) {
    if (num_remaining == 0) {
        return true;
    }

    int n = matches.size();

    for (int w : matches[start]) {
        if (counts[w] == 0) {
            continue;
        }

        int len = lens[w];
        if (start + len > n) {
            continue;
        }

        counts[w]--;

        if (match(start + len, matches, lens, counts, num_remaining - 1)) {
            return true;
        }

        counts[w]++;
    }

    return false;
}

vector<int> SubstringConcatSolution::findSubstring(string s, vector<string> &words) {
    if (s.empty() || words.empty()) {
        return {};
    }

    int total_len = total_length(words);
    if (total_len > s.length()) {
        return {};
    }

    auto words_counts = unique(words);
    vector<string> unique_words = words_counts.first;
    vector<int> counts = words_counts.second;

    vector<int> lens;
    for (const string &w : unique_words) {
        lens.push_back(w.size());
    }

    vector<vector<int>> matches = calculate_matches(s, unique_words);

    return find_matches(matches, lens, counts);
}
