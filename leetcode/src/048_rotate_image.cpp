#include "048_rotate_image.h"


void RotateImageSolution::rotate_blocks(vector<vector<int>> &m) {
    int n = m.size();
    if (n <= 1) {
        return;
    }

    int h = (n + 1) / 2;
    int h1 = h;
    if (n % 2 == 1) {
        h1 = h1 - 1;
    }

    for (int i1 = 0; i1 < h1; i1++) {
        for (int j1 = 0; j1 < h; j1++) {
            int i2 = j1;
            int j2 = n - 1 - i1;

            int i3 = n - 1 - i1;
            int j3 = n - 1 - j1;

            int i4 = n - 1 - j1;
            int j4 = i1;

            int tmp = m[i4][j4];
            m[i4][j4] = m[i3][j3];
            m[i3][j3] = m[i2][j2];
            m[i2][j2] = m[i1][j1];
            m[i1][j1] = tmp;
        }
    }
}

void RotateImageSolution::transpose(vector<vector<int>> &m) {
    int n = m.size();
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
    }
}

void RotateImageSolution::reverse_rows(vector<vector<int>> &m) {
    int n = m.size();
    int n2 = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n2; j++) {
            int k = n - 1 - j;
            int tmp = m[i][j];
            m[i][j] = m[i][k];
            m[i][k] = tmp;
        }
    }
}

void RotateImageSolution::rotate_transpose_reverse(vector<vector<int>> &m) {
    if (m.size() == 1) {
        return;
    }
    transpose(m);
    reverse_rows(m);
}


void RotateImageSolution::rotate(vector<vector<int>> &m) {
    return rotate_transpose_reverse(m);
}
