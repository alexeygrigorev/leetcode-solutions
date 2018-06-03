#include "010_regexp.h"

using namespace std;

bool match(string s, string p) {
//    printf("%s ~= %s\n", s.c_str(), p.c_str());

    int plen = p.length();
    int slen = s.length();

    if (slen == 0) {
        if (plen >= 2 && p[1] == '*') {
            return match(s, p.substr(2));
        }
        return plen == 0;
    }

    char pc = p[0];
    char sc = s[0];

    if (plen > 1 && p[1] == '*') {
//        printf(" - got a star\n");
        if (pc == '.') {
            if (plen == 2) {
                return true;
            }
//            printf("check if need backtrack for %s ~= %s\n", s.c_str(), p.c_str());
//            printf(" - what about %s ~= %s?\n", s.substr(1).c_str(), p.substr(0).c_str());
            bool b1 = match(s.substr(1), p);
            if (b1) {
                return true;
            }
//            printf(" - what about %s ~= %s?\n", s.substr(1).c_str(), p.substr(2).c_str());
            bool b2 = match(s.substr(1), p.substr(2));
            if (b2) {
                return true;
            }
//            printf(" - what about %s ~= %s?\n", s.substr(0).c_str(), p.substr(2).c_str());
            return match(s, p.substr(2));
        }

        int i = 0;
        while (i < slen) {
            if (pc == s[i]) {
                i++;
            } else {
                break;
            }
        }

//        printf(" - try simple match %s ~= %s\n", s.substr(i).c_str(), p.substr(2).c_str());
        bool simple_match = match(s.substr(i), p.substr(2));
        if (simple_match) {
            return true;
        }

//        printf("check if need backtrack for %s ~= %s\n", s.c_str(), p.c_str());
        if (pc != sc) {
            return false;
        }

//        printf(" - what about %s ~= %s?\n", s.substr(1).c_str(), p.substr(2).c_str());
        bool b1 = match(s.substr(1), p.substr(2));
        if (b1) {
            return b1;
        }
//        printf(" - what about %s ~= %s?\n", s.substr(1).c_str(), p.substr(0).c_str());
        bool b2 = match(s.substr(1), p.substr(0));
        if (b2) {
            return b2;
        }
        return match(s.substr(0), p.substr(2));
    }

    if (pc == sc || pc == '.') {
//        printf(" - simple match, continue with %s ~= %s\n",
//               s.substr(1).c_str(), p.substr(1).c_str());
        return match(s.substr(1), p.substr(1));
    } else {
//        printf(" - %s ~!= %s\n", s.c_str(), p.c_str());
        return false;
    }
}

bool RegexpSolution::isMatch(string s, string p) {
    return match(s, simplify(p));
}

string RegexpSolution::simplify(string p) {
    int plen = p.length();
    string res;

    for (int i = 0; i < plen; i++) {
        char pch = p[i];
        if (i < plen - 1 && p[i + 1] == '*') {
            if (i < plen - 3 && p[i + 3] == '*') {
                if (pch == p[i + 2]) {
                    i++;
                    continue;
                }
            }
        }
        res.push_back(pch);
    }

    return res;
}
