#include "479_palindrome_product.h"
#include "gtest/gtest.h"

using namespace std;

PalindromeProductSolution *solution479 = new PalindromeProductSolution;

TEST(PalindromeProductSolution, PalindromeTest0) {
    bool actual = solution479->is_palindrome(201);
    bool expected = false;
    EXPECT_EQ(actual, expected);
}

TEST(PalindromeProductSolution, PalindromeTest1) {
    bool actual = solution479->is_palindrome(202);
    bool expected = true;
    EXPECT_EQ(actual, expected);
}

TEST(PalindromeProductSolution, PalindromeTest2) {
    bool actual = solution479->is_palindrome(22);
    bool expected = true;
    EXPECT_EQ(actual, expected);
}

TEST(PalindromeProductSolution, PalindromeTest3) {
    bool actual = solution479->is_palindrome(21);
    bool expected = false;
    EXPECT_EQ(actual, expected);
}

TEST(PalindromeProductSolution, PalindromeTest4) {
    bool actual = solution479->is_palindrome(92129);
    bool expected = true;
    EXPECT_EQ(actual, expected);
}

TEST(PalindromeProductSolution, PalindromeTest5) {
    bool actual = solution479->is_palindrome(1);
    bool expected = true;
    EXPECT_EQ(actual, expected);
}


TEST(PalindromeProductSolution, Test2) {
    int actual = solution479->largestPalindrome(2);
    int expected = 987 % 1337;
    EXPECT_EQ(actual, expected);
}

TEST(PalindromeProductSolution, Test3) {
    int actual = solution479->largestPalindrome(3);
    int expected = 906609 % 1337;
    EXPECT_EQ(actual, expected);
}

TEST(PalindromeProductSolution, Test4) {
    int actual = solution479->largestPalindrome(4);
    int expected = 99000099 % 1337;
    EXPECT_EQ(actual, expected);
}

TEST(PalindromeProductSolution, Test5) {
    int actual = solution479->largestPalindrome(5);
    int expected = 9966006699L % 1337;
    EXPECT_EQ(actual, (int) expected);
}

TEST(PalindromeProductSolution, Test6) {
    int actual = solution479->largestPalindrome(6);
    int expected = 999000000999L % 1337;
    EXPECT_EQ(actual, (int) expected);
}

TEST(PalindromeProductSolution, Test7) {
    int actual = solution479->largestPalindrome(7);
    int expected = 99956644665999L % 1337;
    EXPECT_EQ(actual, (int) expected);
}

TEST(PalindromeProductSolution, Test8) {
    int actual = solution479->largestPalindrome(8);
    int expected = 9999000000009999L % 1337;
    EXPECT_EQ(actual, (int) expected);
}