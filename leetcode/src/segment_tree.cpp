#include "segment_tree.h"

SumSegmentTree::SumSegmentTree(vector<int> &nums) {
    this->size = nums.size();
    this->values = vector<int>(4 * size, 0);
    build(nums, 0, 0, size - 1);
}

void SumSegmentTree::build(vector<int> &nums, int node_idx, int from, int to) {
    if (to == from) {
        int result = nums[from];
        values[node_idx] = result;
        return;
    }

    int middle = (to + from) / 2;

    int left = left_child(node_idx);
    int right = right_child(node_idx);

    build(nums, left, from, middle);
    build(nums, right, middle + 1, to);

    values[node_idx] = values[left] + values[right];
}

int SumSegmentTree::left_child(int idx) {
    return 2 * idx + 1;
}

int SumSegmentTree::right_child(int idx) {
    return 2 * idx + 2;
}

int SumSegmentTree::sum(int from, int to) {
    return do_sum(0, from, to, 0, size - 1);
}

int SumSegmentTree::do_sum(int node_idx, int from, int to, int segment_start, int segment_end) {
    if (segment_start == from && segment_end == to) {
        return values[node_idx];
    }

    int middle = segment_start + (segment_end - segment_start) / 2;

    // left
    if (from <= middle && to <= middle) {
        int left_node = left_child(node_idx);
        return do_sum(left_node, from, to, segment_start, middle);
    }

    // right
    if (to > middle && from > middle) {
        int right_node = right_child(node_idx);
        return do_sum(right_node, from, to, middle + 1, segment_end);
    }

    // split
    int left_node = left_child(node_idx);
    int left = do_sum(left_node, from, middle, segment_start, middle);

    int right_node = right_child(node_idx);
    int right = do_sum(right_node, middle + 1, to, middle + 1, segment_end);

    return left + right;
}

void SumSegmentTree::update(int i, int val) {
    do_update(0, 0, size - 1, i, val);
}

void SumSegmentTree::do_update(int node_idx, int from, int to, int i, int val) {
    if (from == to) {
        values[node_idx] = val;
        return;
    }

    int middle = (to + from) / 2;
    int left = left_child(node_idx);
    int right = right_child(node_idx);

    if (i <= middle) {
        do_update(left, from, middle, i, val);
    } else {
        do_update(right, middle + 1, to, i, val);
    }

    values[node_idx] = values[left] + values[right];
}
