#include "segment_tree.h"
#include "gtest/gtest.h"

using namespace std;

TEST(SumSegmentTree, TestBuildSum1) {
    vector<int> array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    SumSegmentTree st(array);

    EXPECT_EQ(st.sum(0, 11), 66);
    EXPECT_EQ(st.sum(2, 7), 2 + 3 + 4 + 5 + 6 + 7);
    EXPECT_EQ(st.sum(1, 1), 1);
    EXPECT_EQ(st.sum(6, 10), 6 + 7 + 8 + 9 + 10);
}

TEST(SumSegmentTree, TestBuildSum2) {
    vector<int> array = { 1 };
    SumSegmentTree st(array);

    EXPECT_EQ(st.sum(0, 0), 1);
}

TEST(SumSegmentTree, TestUpdate1) {
    vector<int> array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    SumSegmentTree st(array);

    EXPECT_EQ(st.sum(0, 11), 66);
    st.update(5, 50);
    EXPECT_EQ(st.sum(0, 11), 66 - 5 + 50);
    EXPECT_EQ(st.sum(5, 5), 50);
}
