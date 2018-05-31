#include "479_palindrome_product.h"
#include <vector>

using namespace std;

int PalindromeProductSolution::largestPalindrome(int n) {
    long max = 1;
    long pow = n;
    while (pow > 0) {
        max = max * 10;
        pow--;
    }

    long min = max / 10;
    max = max - 1;

    for (long k = max; k >= min; k = k - 2) {
        if (k % 10 == 5) {
            continue;
        }

        for (long i = k + 2; i <= max; i = i + 2) {
            if ((k % 10) * (i % 10) % 10 != 9) {
                continue;
            }

            long candidate = i * k;
            if (!is_palindrome(candidate)) {
                continue;
            }

            return candidate % 1337;
        }
    }

    // well well...
    return -1;
}

bool PalindromeProductSolution::is_palindrome(long p) {
    vector<int> res;

    long div = p;
    while (div > 0) {
        res.push_back(div % 10);
        div = div / 10;
    }

    int size = res.size();
    for (int i = 0; i < size / 2; i++) {
        if (res[i] != res[size - i - 1]) {
            return false;
        }
    }

    return true;
}
