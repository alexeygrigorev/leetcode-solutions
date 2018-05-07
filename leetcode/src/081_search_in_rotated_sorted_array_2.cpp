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
        m++;
        m_after++;
        after = nums[m_after];
    }

    if (mid >= before && mid > after) {
        // m is the pivot (the largest)
        return m;
    }

    if (mid < before && mid <= after) {
        // m is the smallest, m - 1 is the pivot
        return m_before;
    }

    if (mid > nums.front()) {
        // left part already sorted
        // so pivot is in the right part
        return find_pivot(nums, m + 1, end);
    }

    if (m_before == start) {
        // reached the beginning
        // so pivot must be in the right part
        return find_pivot(nums, m + 1, end);
    }

    if (mid < nums.back()) {
        // right part is already sorted
        // so pivot is in the left part
        return find_pivot(nums, start, m);
    }

    if (m_after == end - 1) {
        // reached the end
        // so pivot must be in the left part
        return find_pivot(nums, start, m);
    }

    printf("cant find pivot\n");
    return 0;
}

bool SearchRotatedSortedArray2Solution::pivoted_search(vector<int> nums, int target) {
    int begin = 0;
    int end = nums.size();
    int first = nums[begin];
    int last = nums[end - 1];

    if (first == target) {
        return true;
    }

    if (last == target) {
        return true;
    }

    while (first == last) {
        end--;
        last = nums[end - 1];
    }

    if (first < last) {
        return bin_search(nums, target, begin, end);
    }

    int ipiv = find_pivot(nums, begin, end);
    int ipiv_next = ipiv + 1;
    int largest = nums[ipiv];
    int smallest = nums[ipiv_next];

    while (largest == smallest && ipiv_next < end - 1) {
        ipiv_next++;
        smallest = nums[ipiv_next];
    }

    if (target >= first && target <= largest) {
        return bin_search(nums, target, begin, ipiv + 1);
    }

    if (target >= smallest && target <= last) {
        return bin_search(nums, target, ipiv, end);
    }

    return false;
}

bool SearchRotatedSortedArray2Solution::search(vector<int> &nums, int target) {
    if (nums.size() <= 5) {
        return find_sequential(nums, target);
    }
    return pivoted_search(nums, target);
}