#include "010_regexp.h"

using namespace std;

bool RegexpSolution::isMatch(string s, string p) {
    printf("%s ~= %s\n", s.c_str(), p.c_str());

    int plen = p.length();
    int slen = s.length();

    if (slen == 0) {
        if (plen == 2) {
            return p[1] == '*';
        }
        return plen == 0;
    }

    char pc = p[0];
    char sc = s[0];

    if (plen > 1 && p[1] == '*') {
        if (pc == '.') {
            if (plen == 2) {
                return true;
            }
            printf("check if need backtrack for %s ~= %s\n", s.c_str(), p.c_str());
            bool b1 = isMatch(s.substr(1), p);
            if (b1) {
                return true;
            }
            bool b2 = isMatch(s.substr(1), p.substr(2));
            if (b2) {
                return true;
            }
            return isMatch(s, p.substr(2));
        }

        int i = 0;
        while (i < slen) {
            if (pc == s[i]) {
                i++;
            } else {
                break;
            }
        }

        bool simple_match = isMatch(s.substr(i), p.substr(2));
        if (simple_match) {
            return true;
        } else if (plen > 2 && slen > 1) {
            printf("check if need backtrack for %s ~= %s\n", s.c_str(), p.c_str());
            if (pc != sc) {
                return false;
            }
            printf(" - what about %s ~= %s?\n", s.substr(1).c_str(), p.substr(2).c_str());

            bool b1 = isMatch(s.substr(1), p.substr(2));
            if (b1) {
                return b1;
            }
            printf(" - what about %s ~= %s?\n", s.substr(1).c_str(), p.substr(0).c_str());
            return isMatch(s.substr(1), p.substr(0));
        }
    }

    if (pc == sc || pc == '.') {
        return isMatch(s.substr(1), p.substr(1));
    } else {
        return false;
    }
}
