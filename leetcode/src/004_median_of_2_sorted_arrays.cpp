#include <string>
#include <vector>
#include <iostream>

#include "004_median_of_2_sorted_arrays.h"

using namespace std;

double MedianOfSortedArraysSolution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
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
