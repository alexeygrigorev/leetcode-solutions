#include "006_zigzag_conversion.h"
#include "gtest/gtest.h"

using namespace std;

ZigZagConversionSolution *solution006 = new ZigZagConversionSolution;

TEST(ZigZagConversion, Test0) {
    string actual = solution006->convert("PAYPALISHIRING", 3);
    EXPECT_EQ(actual, "PAHNAPLSIIGYIR");
}

TEST(ZigZagConversion, Test1) {
    string actual = solution006->convert("PAYPALISHIRING", 4);
    EXPECT_EQ(actual, "PINALSIGYAHRPI");
}

TEST(ZigZagConversion, Test2) {
    string actual = solution006->convert("PAYPALISHIRING", 1);
    EXPECT_EQ(actual, "PAYPALISHIRING");
}

TEST(ZigZagConversion, Test3) {
    string actual = solution006->convert("PAYPALISHIRING", 2);
    EXPECT_EQ(actual, "PYAIHRNAPLSIIG");
}

TEST(ZigZagConversion, Test4) {
    string actual = solution006->convert("nwnk", 1);
    EXPECT_EQ(actual, "nwnk");
}