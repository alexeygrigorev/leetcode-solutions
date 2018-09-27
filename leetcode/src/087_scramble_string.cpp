#include <algorithm>
#include "087_scramble_string.h"

bool ScrambleStringSolution::is_anagram(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

bool ScrambleStringSolution::isScramble(string s1, string s2) {
    if (s1 == s2) {
        return true;
    }

    if (!is_anagram(s1, s2)) {
        return false;
    }

    int n = s1.length();

    for (int i = 1; i <= n - 1; i++) {
        string s1_left = s1.substr(0, i);
        string s1_right = s1.substr(i);

        string s2_left = s2.substr(0, i);
        string s2_right = s2.substr(i);

        if (isScramble(s1_left, s2_left) && isScramble(s1_right, s2_right)) {
            return true;
        }

        string s2_left_scrambled = s2.substr(n - i);
        string s2_right_scrambled = s2.substr(0, n - i);

        if (isScramble(s1_left, s2_left_scrambled) &&
                isScramble(s1_right, s2_right_scrambled)) {
            return true;
        }
    }

    return false;

}
