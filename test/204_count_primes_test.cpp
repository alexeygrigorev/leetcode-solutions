#include "204_count_primes.h"
#include "gtest/gtest.h"

using namespace std;

CountPrimesSolution *solution204 = new CountPrimesSolution;

TEST(CountPrimes, Test0) {
    int actual = solution204->countPrimes(10);
    int expected = 4;
    EXPECT_EQ(actual, expected);
}

TEST(CountPrimes, Test1) {
    int actual = solution204->countPrimes(100);
    int expected = 25;
    EXPECT_EQ(actual, expected);
}

TEST(CountPrimes, Test2) {
    int actual = solution204->countPrimes(10000);
    int expected = 1229;
    EXPECT_EQ(actual, expected);
}

TEST(CountPrimes, Test3) {
    int actual = solution204->countPrimes(100000);
    int expected = 9592;
    EXPECT_EQ(actual, expected);
}

TEST(CountPrimes, Test4) {
    int actual = solution204->countPrimes(200000);
    int expected = 17984;
    EXPECT_EQ(actual, expected);
}

TEST(CountPrimes, Test5) {
    int actual = solution204->countPrimes(2000000);
    int expected = 148933;
    EXPECT_EQ(actual, expected);
}