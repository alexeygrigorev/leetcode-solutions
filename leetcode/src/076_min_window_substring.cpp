#include <climits>
#include <unordered_set>
#include "076_min_window_substring.h"

string MinWindowSubstringSolution::min_window_naive(string s, string t) {
    if (s.length() == 0 || t.length() == 0) {
        return "";
    }

    int num_chars = t.size();
    vector<int> cnt(256, 0);

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
        int total_cnt = num_chars;
        vector<int> cnt_copy = cnt;
        int start = candidate_pos[i];

        for (int j = i; j < num_matches; j++) {
            int end = candidate_pos[j];
            int len = end - start + 1;
            if (len > min_len) {
                break;
            }

            char c = candidate_str[j];

            if (cnt_copy[c] == 0) {
                continue;
            }

            cnt_copy[c]--;
            total_cnt--;


            if (total_cnt == 0) {
                if (len < min_len) {
                    min_len = len;
                    best_start = i;
                }
                break;
            }
        }
    }

    if (best_start == -1) {
        return "";
    }

    return s.substr(candidate_pos[best_start], min_len);
}

class CharMultiset {
private:
    vector<int> cnt;
    unordered_set<int> nonzero_elements;

public:
    CharMultiset() : cnt(vector<int>(256, 0)), nonzero_elements(unordered_set<int>()) {}

    void add(char c) {
        if (cnt[c] == 0) {
            nonzero_elements.insert(c);
        }
        cnt[c]++;
    }

    void remove(char c) {
        if (cnt[c] == 0) {
            return;
        }

        cnt[c]--;
        if (cnt[c] == 0) {
            nonzero_elements.erase(c);
        }
    }

    bool contains(char c) {
        return cnt[c] > 0;
    }

    bool covers(const CharMultiset &other) {
        for (char c : other.nonzero_elements) {
            if (cnt[c] < other.cnt[c]) {
                return false;
            }
        }
        return true;
    }
};

string MinWindowSubstringSolution::min_window_two_indexes(string s, string t) {
    if (s.length() == 0 || t.length() == 0) {
        return "";
    }

    int num_chars = t.size();
    CharMultiset cnt;

    for (char c : t) {
        cnt.add(c);
    }

    vector<int> candidate_pos;
    vector<char> candidate_str;

    for (int i = 0; i < s.size(); i++) {
        if (cnt.contains(s[i])) {
            candidate_pos.push_back(i);
            candidate_str.push_back(s[i]);
        }
    }

    int num_matches = candidate_str.size();

    if (num_matches < num_chars) {
        return "";
    }

    int min_len = INT_MAX;
    int best_start = -1;

    int left = 0;
    int right = 0;

    CharMultiset window;

    while (right < num_matches) {
        // go as far as possible
        while (right < num_matches) {
            char c = candidate_str[right];
            window.add(c);
            if (window.covers(cnt)) {
                break;
            }
            right++;
        }

        // reached end, but not covering
        if (!window.covers(cnt)) {
            break;
        }

        // find min
        while (left < right) {
            char c = candidate_str[left];
            window.remove(c);
            if (!window.covers(cnt)) {
                break;
            }
            left++;
        }

        int len = candidate_pos[right] - candidate_pos[left] + 1;
        if (len < min_len) {
            min_len = len;
            best_start = left;
        }

        // now remove one letter and find the next match
        left++;
        right++;
    }

    if (best_start == -1) {
        return "";
    }

    return s.substr(candidate_pos[best_start], min_len);
}

string MinWindowSubstringSolution::min_window_optimized(string s, string t) {
    if (s.empty() || t.empty() || s.length() < t.length()) {
        return "";
    }

    vector<int> counts(128, 0);
    for (char c : t) {
        counts[c]++;
    }

    int total_count = t.length();
    int left = 0;
    int best_len = INT_MAX;
    int best_left = -1;

    for (int right = 0; right < s.length(); right++) {
        char cr = s[right];

        if (counts[cr] > 0) {
            total_count--;
        }
        counts[cr]--;

        while (total_count == 0) {
            char cl = s[left];
            int len = right - left + 1;
            if (len < best_len) {
                best_len = len;
                best_left = left;
            }

            counts[cl]++;
            if (counts[cl] > 0) {
                total_count++;
            }

            left++;
        }
    }

    if (best_left == -1) {
        return "";
    }

    return s.substr(best_left, best_len);
}

string MinWindowSubstringSolution::minWindow(string s, string t) {
    return min_window_optimized(s, t);
}
