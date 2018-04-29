#include <string>
#include <vector>

#include "020_valid_parentheses.h"

using namespace std;

bool is_valid_parentheses_stack(string s) {
    vector<char> stack;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '[' || c == '(' || c == '{') {
            stack.push_back(c);
        } else if (c == ']' || c == ')' || c == '}') {
            if (stack.size() == 0) {
                return false;
            }

            char prev = stack.back();
            stack.pop_back();

            if (prev == '[' && c != ']') {
                return false;
            }
            if (prev == '{' && c != '}') {
                return false;
            }
            if (prev == '(' && c != ')') {
                return false;
            }
        }
    }

    return stack.size() == 0;
}

bool ValidParenthesesSolution::isValid(string s) {
    return is_valid_parentheses_stack(s);
}