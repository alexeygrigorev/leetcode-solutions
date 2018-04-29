#include <string>
#include <vector>
#include <iostream>
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

        if (balance == 0) {
            best_end = i;
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

int longest_valid_parentheses_matching(string s) {
    int size = s.size();
    vector<int> end_ptr(size, -1);
    vector<int> stack;

    for (int i = 0; i < size; i++) {
        char c = s[i];
        // (

        if (c == '(') {
            stack.push_back(i);
            continue;
        }

        // )
        if (stack.size() == 0) {
            continue;
        }

        int begin = stack.back();
        stack.pop_back();

        end_ptr[begin] = i;
    }

    int best_len = 0;
    int i = 0;

    while (i < size) {
        int current_len = 0;
        while (end_ptr[i] != -1 && i < size) {
            int next = end_ptr[i];
            int len = next - i + 1;
            current_len = current_len + len;
            i = next + 1;
        }

        if (current_len > best_len) {
            best_len = current_len;
        }

        i++;
    }

    return best_len;
}

int LongestValidParenthesesSolution::longestValidParentheses(string s) {
    return longest_valid_parentheses_matching(s);
}