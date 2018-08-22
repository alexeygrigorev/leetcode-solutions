#include "048_rotate_image.h"

void RotateImageSolution::rotate(vector<vector<int>> &m) {
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
