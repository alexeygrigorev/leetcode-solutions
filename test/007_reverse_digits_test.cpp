#include "007_reverse_digits.h"
#include "gtest/gtest.h"

using namespace std;

ReverseDigitsSolution *solution007 = new ReverseDigitsSolution;

TEST(ReverseDigitsSolution, Test0) {
    int actual = solution007->reverse(123);
    EXPECT_EQ(actual, 321);
}

TEST(ReverseDigitsSolution, Test1) {
    int actual = solution007->reverse(-123);
    EXPECT_EQ(actual, -321);
}

TEST(ReverseDigitsSolution, Test2) {
    int actual = solution007->reverse(120);
    EXPECT_EQ(actual, 21);
}

TEST(ReverseDigitsSolution, Test3) {
    int actual = solution007->reverse(1534236469);
    EXPECT_EQ(actual, 0);
}



