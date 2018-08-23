#include <string>
#include <unordered_set>

#include "003_longest_substring.h"

using namespace std;


int lengthOfLongestSubstring_naive(string &s) {
    int len = s.length();
    if (len == 0) {
        return 0;
    }

    int max = 1;

    for (int i = 0; i < len; i++) {
        unordered_set<char> set = unordered_set<char>();
        set.insert(s[i]);
        int current_max = 1;

        for (int k = i + 1; k < len; k++) {
            if (set.count(s[k]) > 0) {
                break;
            }

            set.insert(s[k]);
            current_max++;
        }

        if (current_max > max) {
            max = current_max;
        }
    }

    return max;
}

int lengthOfLongestSubstring_linear(string &s) {
    /*
     * Algorithm:
     *
     * We keep the following variables:
     * - substring_start: start of the current substring
     * - seen_pos: nodes of each char to the index it was seen previously (-1 at start)
     *
     * The current longest substring starts from the same position as previously
     * except when we already saw this char. Then the starting position
     * moves to the character after.
     *
     */

    int len = s.length();
    if (len == 0) {
        return 0;
    }

    int seen_pos[128];
    for (int i = 0; i < 128; i++) {
        seen_pos[i] = -1;
    }

    int largest_len = 0;
    int substring_start = 0;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        int prev_pos = seen_pos[c];
        if (substring_start < prev_pos + 1) {
            substring_start = prev_pos + 1;
        }

        seen_pos[c] = i;

        int current_len = i - substring_start + 1;
        if (current_len > largest_len) {
            largest_len = current_len;
        }
    }

    return largest_len;
}

int LongestSubstringSolution::lengthOfLongestSubstring(string s) {
    return lengthOfLongestSubstring_linear(s);
};