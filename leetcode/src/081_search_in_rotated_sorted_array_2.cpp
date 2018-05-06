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

bool SearchRotatedSortedArray2Solution::bin_search(vector<int> &nums, int t, int start, int end) {
    if (start >= end) {
        return false;
    }

    int m = start + (end - start) / 2;
    int mid = nums[m];
    if (mid == t) {
        return true;
    }

    if (t < mid) {
        return bin_search(nums, t, start, m);
    } else {
        return bin_search(nums, t, m + 1, end);
    }
}

int SearchRotatedSortedArray2Solution::find_pivot(vector<int> nums, int start, int end) {
    int m = start + (end - start) / 2;
    int m_before = m - 1;
    int m_after = m + 1;

    int mid = nums[m];

    int before = nums[m_before];
    while (before == mid && m_before > start) {
        m_before--;
        before = nums[m_before];
    }

    int after = nums[m_after];
    while (after == mid && m_after < end - 1) {
        m_after++;
        after = nums[m_after];
    }

    printf("before=%d, mid=%d, after=%d\n", before, mid, after);

    if (mid > before && mid > after) {
        // m is the pivot (the largest)
        return m;
    }

    if (mid < before && mid < after) {
        // m is the smallest, m - 1 is the pivot
        return m_before;
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

int SearchRotatedSortedArray2Solution::pivoted_search(vector<int> nums, int target) {
    int first = nums.front();
    int last = nums.back();

    if (first < last) {
        return bin_search(nums, target, 0, nums.size());
    }

    int ipiv = find_pivot(nums, 0, nums.size());
    int ipiv_next = ipiv + 1;
    int largest = nums[ipiv];
    int smallest = nums[ipiv_next];

    while (largest == smallest && ipiv_next < nums.size() - 1) {
        ipiv_next++;
        smallest = nums[ipiv_next];
    }

    printf("pivot=%d, largest=%d, smallest=%d\n", ipiv, largest, smallest);

    if (target >= first && target <= largest) {
        return bin_search(nums, target, 0, ipiv + 1);
    }

    if (target >= smallest && target <= last) {
        return bin_search(nums, target, ipiv, nums.size());
    }

    return false;
}

bool SearchRotatedSortedArray2Solution::search(vector<int> &nums, int target) {
    if (nums.size() <= 5) {
        return find_sequential(nums, target);
    }
    return pivoted_search(nums, target);
}