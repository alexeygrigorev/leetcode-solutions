#include <climits>
#include "076_min_window_substring.h"

string MinWindowSubstringSolution::min_window_naive(string s, string t) {
    if (s.length() == 0 || t.length() == 0) {
        return "";
    }

    int num_chars = t.size();
    vector<int> cnt(256, 0);

    int matches = 0;
    for (char c : t) {
        cnt[c]++;
    }

    vector<int> candidate_pos;
    vector<char> candidate_str;

    for (int i = 0; i < s.size(); i++) {
        if (cnt[s[i]] == 0) {
            continue;
        }

        candidate_pos.push_back(i);
        candidate_str.push_back(s[i]);
    }

    int num_matches = candidate_str.size();

    if (num_matches < num_chars) {
        return "";
    }

    int min_len = INT_MAX;
    int best_start = -1;

    for (int i = 0; i < num_matches - num_chars + 1; i++) {
        // printf("trying i = %d\n", i);
        int total_cnt = num_chars;
        vector<int> cnt_copy = cnt;
        int start = candidate_pos[i];

        for (int j = i; j < num_matches; j++) {
            int end = candidate_pos[j];
            int len = end - start + 1;
            if (len > min_len) {
                // printf("no point trying, exiting\n");
                break;
            }

            char c = candidate_str[j];
            // printf("char s[%d]=%c, total_cnt = %d\n", i, c, total_cnt);

            if (cnt_copy[c] == 0) {
                continue;
            }

            cnt_copy[c]--;
            total_cnt--;


            if (total_cnt == 0) {
                if (len < min_len) {
                    min_len = len;
                    best_start = i;
                    // printf("new best len %d\n", min_len);
                }
                break;
            }
        }
        // printf("done i = %d ;\n", i);
    }

    if (best_start == -1) {
        return "";
    }

    return s.substr(candidate_pos[best_start], min_len);
}

string MinWindowSubstringSolution::minWindow(string s, string t) {
    return min_window_naive(s, t);
}
