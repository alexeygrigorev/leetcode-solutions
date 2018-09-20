#include "307_range_sum_query.h"

RangeSumArray::RangeSumArray(vector<int> nums) {
    if (nums.empty()) {
        st = nullptr;
        return;
    }
    st = new SumSegmentTree(nums);
}

void RangeSumArray::update(int i, int val) {
    if (st == nullptr) {
        return;
    }
    st->update(i, val);
}

int RangeSumArray::sumRange(int i, int j) {
    if (st == nullptr) {
        return 0;
    }
    return st->sum(i, j);
}

