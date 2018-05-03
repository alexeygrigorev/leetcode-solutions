#include <vector>
#include "007_reverse_digits.h"

using namespace std;

int sign(int x) {
    if (x > 0) {
        return 1;
    } else {
        return -1;
    }
}

int reverse_vector(int x) {
    vector<int> digits;

    int s = sign(x);
    int div = s * x;
    int mod;

    while (div != 0) {
        mod = div % 10;
        div = div / 10;
        digits.push_back(mod);
    }

    int result = 0;
    int pow = 1;

    while (digits.size() != 0) {
        int last = digits.back();
        digits.pop_back();

        result = result + pow * last;
        int check = result / pow;
        if (check != last) {
            return 0;
        }

        pow = pow * 10;
    }

    return s * result;
}

int ReverseDigitsSolution::reverse(int x) {
    return reverse_vector(x);
}