#include <string>
#include <vector>
#include <debug.h>

#include "004_median_of_2_sorted_arrays.h"

using namespace std;

double median_with_mergesort(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    int total_len = len1 + len2;
    vector<int> merge;

    int pos1 = 0;
    int pos2 = 0;

    while (pos1 < len1 && pos2 < len2) {
        if (nums1[pos1] < nums2[pos2]) {
            merge.push_back(nums1[pos1]);
            pos1++;
        } else {
            merge.push_back(nums2[pos2]);
            pos2++;
        }
    }

    while (pos1 < len1) {
        merge.push_back(nums1[pos1]);
        pos1++;
    }

    while (pos2 < len2) {
        merge.push_back(nums2[pos2]);
        pos2++;
    }

    if (total_len % 2 == 1) {
        int middle = total_len / 2;
        return merge[middle];
    } else {
        int middle = total_len / 2;
        return  (merge[middle] + merge[middle - 1]) / 2.0;
    }
}

int binary_search(int* v1, int l1, int* v2, int l2, int k) {
    if (l1 == 0) {
        return v2[k - 1];
    }

    if (l2 == 0) {
        return v1[k - 1];
    }

    if (k == 1) {
        return min(v1[0], v2[0]);
    }

    int m = k / 2;
    int k1 = min(l1, m);
    int k2 = min(l2, m);

    if (v1[k1 - 1] < v2[k2 - 1]) {
        return binary_search(&v1[k1], l1 - k1, v2, l2, k - k1);
    } else {
        return binary_search(v1, l1, &v2[k2], l2 - k2, k - k2);
    }
}

double trivial_search(vector<int>& v) {
    int len = (int) v.size();
    if (len % 2 == 0) {
        int k1 = len / 2;
        int k2 = k1 - 1;
        return (v[k1] + v[k2]) / 2.0;
    } else {
        int k = len / 2;
        return v[k];
    }
}

double median_binary_search(vector<int> &v1, vector<int> &v2) {
    int l1 = (int) v1.size();
    int l2 = (int) v2.size();

    if (l1 == 0) {
        return trivial_search(v2);
    }
    if (l2 == 0) {
        return trivial_search(v1);
    }

    int total = l1 + l2;

    if (total % 2 == 0) {
        int k1 = total / 2 + 1;
        int m1 = binary_search(&v1[0], l1, &v2[0], l2, k1);
        int m2 = binary_search(&v1[0], l1, &v2[0], l2, k1 - 1);
        return (m1 + m2) / 2.0;
    } else {
        int k = total / 2 + 1;
        int m = binary_search(&v1[0], l1, &v2[0], l2, k);
        return m;
    }
}

double MedianOfSortedArraysSolution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    return median_binary_search(nums1, nums2);
}
