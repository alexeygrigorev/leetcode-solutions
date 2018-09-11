#include "030_substring_concat.h"

bool SubstringConcatSolution::match(string &s, int start, vector<string> &words, vector<bool> &used, int words_used) {
    if (words_used == words.size()) {
        // printf(" - done!\n");
        return true;
    }

    int len_s = s.length();

    for (int wi = 0; wi < words.size(); wi++) {
        if (used[wi]) {
            continue;
        }

        string word = words[wi];
        int word_len = word.length();

        if (start + word_len > len_s) {
            continue;
        }

        if (s[start] != word[0]) {
            continue;
        }

        string sub = s.substr(start, word_len);

        if (sub != word) {
            continue;
        }

        // printf("- matched %s\n", word.c_str());

        used[wi] = true;
        if (match(s, start + word_len, words, used, words_used + 1)) {
            return true;
        }
        used[wi] = false;
    }

    return false;
}

vector<int> SubstringConcatSolution::findSubstring(string s, vector<string> &words) {
    int len_s = s.length();
    int len_total = 0;
    for (string word : words) {
        len_total = len_total + word.length();
    }

    if (len_s < len_total) {
        return {};
    }

    int num_words = words.size();

    vector<int> result;

    for (int i = 0; i < s.length() - len_total + 1; i++) {
        vector<bool> used(false, num_words);
        if (match(s, i, words, used, 0)) {
            result.push_back(i);
        }
    }

    return result;
}
