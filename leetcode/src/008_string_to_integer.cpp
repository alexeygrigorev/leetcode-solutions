#include "limits.h"
#include "008_string_to_integer.h"

using namespace std;

int my_atoi(string str) {
    int pos = 0;
    int sign = 1;

    int n = str.size();
    int result = 0;

    while (pos < n) {
        char c = str[pos];
        if (c == '-') {
            sign = -1;
            pos++;
            break;
        }
        if (c == '+') {
            sign = 1;
            pos++;
            break;
        }

        if (c == ' ') {
            pos++;
            continue;
        }

        if (c >= '0' && c <= '9') {
            break;
        } else {
            // not a digit, exiting
            return 0;
        }
    }

    while (pos < n) {
        char c = str[pos];
        if (c < '0' || c > '9') {
            break;
        }
        int i = c - '0';
        result = result * 10 + i;

        if (result % 10 != i) {
            if (sign == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }

        pos++;
    }

    if (sign == 1) {
        return result;
    } else {
        return -result;
    }
}

int StringToIntegerSolution::myAtoi(string str) {
    return my_atoi(str);
}