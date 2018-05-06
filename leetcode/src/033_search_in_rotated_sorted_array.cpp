#include <vector>
#include "033_search_in_rotated_sorted_array.h"

using namespace std;

int find_sequential(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        }
    }

    return -1;
}

int bin_search(vector<int> &nums, int t, int start, int end) {
    if (start >= end) {
        return -1;
    }

    int m = start + (end - start) / 2;
    int mid = nums[m];
    if (mid == t) {
        return m;
    }

    if (t < mid) {
        return bin_search(nums, t, start, m);
    } else {
        return bin_search(nums, t, m + 1, end);
    }
}

int pivoted_bin_search(vector<int> &nums, int t, int start, int end) {
    int m = start + (end - start) / 2;
    int mid = nums[m];
    if (mid == t) {
        return m;
    }
    int before = nums[m - 1];
    if (before == t) {
        return m - 1;
    }
    int after = nums[m + 1];
    if (after == t) {
        return m + 1;
    }

    int first = nums[start];
    if (first == t) {
        return start;
    }
    int last = nums[end - 1];
    if (last == t) {
        return end - 1;
    }

    if (before < mid && mid < after) {
        if (mid > first) {
            // start..m is already sorted, pivot is not there
            if (t > first && t < mid) {
                return bin_search(nums, t, start, m);
            } else {
                return pivoted_bin_search(nums, t, m + 1, end);
            }
        }
        if (mid < last) {
            // m..end is already sorted
            if (t > mid && t < last) {
                return bin_search(nums, t, m + 1, end);
            } else {
                return pivoted_bin_search(nums, t, start, m);
            }
        }

        // hm?
    }

    if (mid > before && mid > after) {
        // m is the pivot (the largest)
        if (t > mid) {
            return -1;
        }
        if (t < after) {
            return -1;
        }

        if (t > first) {
            return bin_search(nums, t, start, m);
        } else {
            return bin_search(nums, t, m + 1, end);
        }
    }

    if (mid < before && mid < after) {
        // m is the smallest, m - 1 is the pivot
        if (t > before) {
            return -1;
        }
        if (t < mid) {
            return -1;
        }
        if (t > first) {
            return bin_search(nums, t, start, m - 1);
        } else {
            return bin_search(nums, t, m, end);
        }
    }

    throw exception();
}

int SearchRotatedSortedArraySolution::search(vector<int> &nums, int target) {
    if (nums.size() <= 5) {
        return find_sequential(nums, target);
    }
    if (nums.front() < nums.back()) {
        return bin_search(nums, target, 0, nums.size());
    }
    return pivoted_bin_search(nums, target, 0, nums.size());
}