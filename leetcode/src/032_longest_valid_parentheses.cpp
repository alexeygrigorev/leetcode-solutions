#include <string>
#include "032_longest_valid_parentheses.h"

using namespace std;

int valid_sequence_end(string s, int b) {
    int len = s.length();
    int balance = 0;
    int best_end = b;

    for (int i = b; i < len; i++) {
        if (s[i] == '(') {
            balance++;
        } else if (s[i] == ')') {
            balance--;
        }

        int l = i - b + 1;
//        printf("balance=%d for s[%d:%d]='%s', len=%d\n",
//               balance, b, i+1, s.substr(b, l).c_str(), l);
        if (balance == 0) {
            best_end = i;
//            printf("valid seq s[%d:%d]='%s', len=%d\n",
//               b, best_end+1, s.substr(b, l).c_str(), l);
        }
        if (balance < 0) {
            return best_end;
        }
    }

    return best_end;
}

int longest_valid_parentheses_naive(string s) {
    int i = 0;
    int len = s.size();
    int max_len = 0;

    while (i < len) {
        while (s[i] == ')') {
            i++;
        }
        int e = valid_sequence_end(s, i);
        if (e == i) {
            i++;
            continue;
        }

        int current_len = e - i + 1;

        if (current_len > max_len) {
            max_len = current_len;
        }
        i = e + 1;
    }

    return max_len;
}

int LongestValidParenthesesSolution::longestValidParentheses(string s) {
    return longest_valid_parentheses_naive(s);
}