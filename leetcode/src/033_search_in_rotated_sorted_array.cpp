#include <vector>
#include <algorithm>
#include "033_search_in_rotated_sorted_array.h"

using namespace std;

int rotated_sorted_array_search_naive(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        }
    }

    return - 1;
}

int bin_search(vector<int>& nums, int t, int start, int end) {
    return binary_search(nums.begin() + start, nums.begin() + end, t);
}

int pivoted_bin_search(vector<int>& nums, int t, int start, int end) {
    int m = (end - start) / 2;
    int mid = nums[m];
    if (mid == t) {
        return m;
    }
    int before = nums[m - 1];
    int after = nums[m + 1];

    if (mid > before && mid > after) {
        // mid is the pivot
        return bin_search(nums, t, start, m - 1);
    }

    if (mid < before && mid < after) {
        // before is the pivot
        return bin_search(nums, t, start, m - 2);
    }

    int first = nums.front();
    int last = nums.back();

    if (mid > first && mid < last) {
        // pivot is on the right from m
        if (t < mid) {
            // already sorted before (on the left of) m
            return bin_search(nums, t, start, m - 1);
        } else {
            // pivot is after m (on the right of m)
            return pivoted_bin_search(nums, t, m + 1, end);
        }
    }

    if (mid < first && mid < last) {
        // pivot is on the left from m
        if (t < mid) {
            // pivot is before m (on the left of m)
            return pivoted_bin_search(nums, t, start, m - 1);
        } else {
            // already sorted after (on the right of) m
            return bin_search(nums, t, m + 1, end);
        }
    }

    throw exception();
}

int SearchRotatedSortedArraySolution::search(vector<int>& nums, int target) {
    if (nums.size() <= 5) {
        return rotated_sorted_array_search_naive(nums, target);
    }
    return pivoted_bin_search(nums, target, 0, nums.size());
}