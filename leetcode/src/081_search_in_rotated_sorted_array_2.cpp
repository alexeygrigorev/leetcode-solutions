#include <vector>
#include <cstdio>
#include "081_search_in_rotated_sorted_array_2.h"

using namespace std;


bool SearchRotatedSortedArray2Solution::find_sequential(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return true;
        }
    }

    return false;
}

bool SearchRotatedSortedArray2Solution::rotated_search(vector<int> nums, int target, int start, int end) {
    while (nums[start] == nums[end] && end >= start) {
        end--;
    }
    if (start > end) {
        return false;
    }

    int m = start + (end - start) / 2;
    int left = nums[start];
    int mid = nums[m];
    int right = nums[end];

    if (mid == target) {
        return true;
    }
    if (left == target) {
        return true;
    }
    if (right == target) {
        return true;
    }

    // usual binary search cases
    if (left <= target && target < mid) {
        // go to the left part
        return rotated_search(nums, target, start, m - 1);
    }
    if (mid < target && target <= right) {
        // go to the right part
        return rotated_search(nums, target, m + 1, end);
    }

    // pivot is on the right and the target must be there
    if (mid > right) {
        return rotated_search(nums, target, m + 1, end);
    }

    // pivot is on the left, and the target must be there
    if (mid < left) {
        return rotated_search(nums, target, start, m - 1);
    }

    return false;
}

bool SearchRotatedSortedArray2Solution::search(vector<int> &nums, int target) {
    if (nums.size() <= 5) {
        return find_sequential(nums, target);
    }

    if (nums.front() == target) {
        return true;
    }

    return rotated_search(nums, target, 0, nums.size() - 1);
}