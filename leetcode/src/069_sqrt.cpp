#include <cmath>
#include "069_sqrt.h"

int SqrtSolution::mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    double fx = x;
    double l = 1, r = fx;
    double g;


    while (true) {
        g = (l + r) / 2;

        double diff = g * g - fx;
        if (abs(diff) <= 1e-2) {
            break;
        }
        if (diff < 0) {
            l = g;
        } else {
            r = g;
        }
    }

    double eps = 1e-2;
    if (x > 10000000) {
        eps = 1e-6;
    }

    int result = ceil(g);
    if (result - g <= eps) {
        return result;
    } else {
        return ((int) g);
    }
}
