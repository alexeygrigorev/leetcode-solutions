#include <string>

#include "005_longest_palindrome_substring.h"

using namespace std;

bool is_palindrome(string &s) {
    int size = s.size();
    for (int i = 0; i < size / 2; i++) {
        if (s[i] != s[size - i - 1]) {
            return false;
        }
    }
    return true;
}

string longest_palindrome_naive(string &s) {
    string longest = s.substr(0, 1);
    int longest_len = 1;

    int size = s.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int len = j - i + 1;
            if (len <= longest_len) {
                continue;
            }
            string substr = s.substr(i, len);
            if (is_palindrome(substr)) {
                longest_len = len;
                longest = substr;
            }
        }
    }

    return longest;
}

string longest_palindrome_dp(string &s) {
    int longest_len = 1;
    string longest = s.substr(0, 1);

    int n = s.size();
    bool palindromes[n][n];

    for (int i = 0; i < n; i++) {
        palindromes[i][i] = true;

        for (int j = i - 1; j >= 0; j--) {
            int len = i - j + 1;
            bool palindrome = s[i] == s[j];

            if (len > 2) {
                palindrome = palindrome && palindromes[i-1][j+1];
            }

            palindromes[i][j] = palindrome;

            if (!palindrome) {
                continue;
            }

            if (len > longest_len) {
                longest_len = len;
                longest = s.substr(j, len);
            }
        }
    }

    return longest;
}


string LongestPalindromeSubstringSolution::longestPalindrome(string s) {
    //return longest_palindrome_naive(s);
    return longest_palindrome_dp(s);
}