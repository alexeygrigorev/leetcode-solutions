#include <string>
#include <unordered_set>

#include "003_longest_substring.h"

using namespace std;


int LongestSubstringSolution::lengthOfLongestSubstring(string s) {
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
};