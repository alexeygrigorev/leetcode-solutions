#include "204_count_primes.h"
#include <vector>
#include <cstring>

using namespace std;

bool is_prime(int n, vector<int> &primes_so_far) {
    for (int p : primes_so_far) {
        if (n % p == 0) {
            return false;
        }
    }

    return true;
}

int count_primes_factorization(int n) {
    vector<int> primes;
    primes.push_back(2);

    int count = 2;

    for (int i = 3; i < n; i = i + 2) {
        if (is_prime(i, primes)) {
            primes.push_back(i);
            count++;
        }
    }

    return count;
}

int count_primes_sieve(int n) {
    bool is_prime[n];
    memset(is_prime, true, sizeof(bool) * n);

    int count = 1;

    for (int i = 3; i < n; i = i + 2) {
        if (!is_prime[i]) {
            continue;
        }

        count++;

        for (int j = i + i; j < n; j = j + i) {
            is_prime[j] = false;
        }
    }

    return count;
}

int CountPrimesSolution::countPrimes(int n) {
    return count_primes_sieve(n);
}