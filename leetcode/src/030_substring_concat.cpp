#include "030_substring_concat.h"
#include <unordered_set>
#include <unordered_map>

pair<vector<string>, vector<int>> SubstringConcatSolution::unique(vector<string> &words) {
    vector<int> counts;
    vector<string> unique;

    unordered_map<string, int> ind;
    int pos = 0;

    for (string w : words) {
        if (ind.find(w) == ind.end()) {
            unique.push_back(w);
            counts.push_back(1);
            ind[w] = pos;
            pos++;
        } else {
            int i = ind[w];
            counts[i]++;
        }
    }

    return { unique, counts };
}

vector<int> SubstringConcatSolution::findSubstring(string s, vector<string> &words) {
    if (s.empty() || words.empty()) {
        return {};
    }

    int total_len = 0;
    for (string word : words) {
        int len = word.length();
        total_len = total_len + len;
    }

    if (total_len > s.length()) {
        return {};
    }

    auto words_counts = unique(words);
    vector<string> unique_words = words_counts.first;
    vector<int> counts = words_counts.second;

//    printf("%d unique words\n", unique_words.size());

    vector<int> lens;
    for (string w : unique_words) {
        lens.push_back(w.size());
//        printf("%d, ", lens.back());
    }
//    printf("\n");

    vector<vector<int>> matches = calculate_matches(s, unique_words);
//    for (int i = 0; i < matches.size(); i++) {
//        vector<int> match = matches[i];
//        printf("matches at %d:", i);
//        for (int m : match) {
//            printf(" %d", m);
//        }
//        printf("\n");
//    }

    return find_matches(matches, lens, counts);
}

vector<vector<int>> SubstringConcatSolution::calculate_matches(const string &s, const vector<string> &words) const {
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

//        printf("checking index %d\n", i);
//        printf("counts:");
//        for (int c : counts_copy) {
//            printf(" %d", c);
//        }
//        printf("\n");


        if (match(i, matches, lens, counts_copy, total_cnt)) {
//            printf("match at %d, adding to results\n", i);
            result.push_back(i);
        }
    }

    return result;
}

//void intend(int cnt) {
//    for (int i = 0; i < cnt; i++) {
//        printf("    ");
//    }
//}

bool SubstringConcatSolution::match(int start, vector<vector<int>> &matches,
                                    vector<int> &lens,
                                    vector<int> &counts, int num_remaining) {
//    intend(num_used);
//    printf("match(%d, %d)\n", start, num_used);
    if (num_remaining == 0) {//num_used == lens.size()) {
//        intend(num_used);
//        printf(" - match!\n");
        return true;
    }

    int n = matches.size();

    for (int w : matches[start]) {
//        intend(num_used);
//        printf(" - checking word %d...\n", w);
        if (counts[w] == 0) {
//            intend(num_used);
//            printf(" - already used word %d...\n", w);
            continue;
        }

        int len = lens[w];
        if (start + len > n) {
//            intend(num_used);
//            printf(" - len of %d is too large...\n", w);
            continue;
        }

//        intend(num_used);
//        printf(" - decrement cnt of %d, now ", w);

        counts[w]--;
//        printf("%d\n", counts[w]);

        if (match(start + len, matches, lens, counts, num_remaining - 1)) {
//            intend(num_used);
//            printf(" - found a match!\n");
            return true;
        }

//        intend(num_used);
//        printf(" - increment cnt of %d, now ", w);

        counts[w]++;
//        printf("%d\n", counts[w]);
    }

//    intend(num_used);
//    printf(" - didn't find anything at %d\n", start);
    return false;
}

