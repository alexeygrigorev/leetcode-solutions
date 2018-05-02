#include <string>
#include <cstring>
#include "006_zigzag_conversion.h"

using namespace std;

void print_array(char *arr, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            char c = arr[i * num_cols + j];
            if (c == 0) {
                printf(".");
            } else {
                printf("%c", c);
            }
        }
        printf("\n");
    }
}

string zigzag_naive(string s, int num_rows) {
    if (num_rows == 1) {
        return s;
    }

    int n = s.length();
    char *tmp = new char[num_rows * n];
    memset(tmp, 0, sizeof(char) * num_rows * n);
    print_array(tmp, num_rows, n);

    int pos = 0;
    int row = 0;
    int col = 0;

    while (pos < n) {
        while (row < num_rows && pos < n) {
            tmp[row * n + col] = s[pos];
            print_array(tmp, num_rows, n);
            row++;
            pos++;
        }

        col++;
        row--;
        row--;

        while (row > 0 && pos < n) {
            tmp[row * n + col] = s[pos];
            print_array(tmp, num_rows, n);
            row--;
            col++;
            pos++;
        }
    }


    string result(n, '?');
    int cur_pos = 0;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < col; j++) {
            char c = tmp[i * n + j];
            if (c != 0) {
                result[cur_pos] = c;
                cur_pos++;
            }
        }
    }

    delete tmp;
    return result;
}

string ZigZagConversionSolution::convert(string s, int numRows) {
    return zigzag_naive(s, numRows);
}