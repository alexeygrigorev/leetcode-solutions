#include <vector>
#include <cstdio>
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

int find_pivot(vector<int> nums, int start, int end) {
    int m = start + (end - start) / 2;
    int mid = nums[m];
    int before = nums[m - 1];
    int after = nums[m + 1];

    if (mid > before && mid > after) {
        // m is the pivot (the largest)
        return m;
    }

    if (mid < before && mid < after) {
        // m is the smallest, m - 1 is the pivot
        return m - 1;
    }

    if (mid > nums.front()) {
        // left part already sorted
        // so pivot is in the right part
        return find_pivot(nums, m + 1, end);
    }

    if (mid < nums.back()) {
        // right part is already sorted
        // so pivot is in the left part
        return find_pivot(nums, start, m);
    }

    printf("cant find pivot\n");
    throw exception(); // how did this happen?
}

int pivoted_search(vector<int> nums, int target) {
    int first = nums.front();
    int last = nums.back();

    if (first < last) {
        return bin_search(nums, target, 0, nums.size());
    }

    int ipiv = find_pivot(nums, 0, nums.size());
    int largest = nums[ipiv];
    int smallest = nums[ipiv + 1];

    if (target >= first && target <= largest) {
        return bin_search(nums, target, 0, ipiv + 1);
    }

    if (target >= smallest && target <= last) {
        return bin_search(nums, target, ipiv, nums.size());
    }

    return -1;
}

int rotated_search(vector<int> nums, int target, int start, int end) {
    if (start > end) {
        return -1;
    }

    int m = start + (end - start) / 2;
    int left = nums[start];
    int mid = nums[m];
    int right = nums[end];

    if (mid == target) {
        return m;
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

    return -1;
}


int SearchRotatedSortedArraySolution::search(vector<int> &nums, int target) {
    if (nums.size() <= 5) {
        return find_sequential(nums, target);
    }
    return rotated_search(nums, target, 0, nums.size() - 1);
}