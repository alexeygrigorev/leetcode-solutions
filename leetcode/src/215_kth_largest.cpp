#include <string>
#include <vector>
#include <algorithm>

#include "215_kth_element.h"
#include "debug.h"

using namespace std;

void swap(int *a, int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int hoare_partition(int *a, int l, int r) {
    int p = a[l];
    int i = l;
    int j = r;

    while (true) {
        while (a[i] < p && i <= j) {
            i++;
        }
        while (a[j] > p && j >= i) {
            j--;
        }

        if (i >= j) {
            return j;
        }

        swap(a, i, j);
        i++;
        j--;
    }
}

void partial_quicksort(int *a, int l, int r, int i) {
    if (l >= r) {
        return;
    }

    int pi = hoare_partition(a, l, r);

    if (i <= pi) {
        partial_quicksort(a, l, pi, i);
    } else {
        partial_quicksort(a, pi + 1, r, i);
    }
}

int KthLargestSolution::findKthLargest(vector<int> &nums, int k) {
    random_shuffle(nums.begin(), nums.end());
    int len = (int) nums.size();
    int i = len - k;
    partial_quicksort(&nums[0], 0, len - 1, i);
    return nums[i];
}

int KthLargestSolution::findKthLargestSortBaseline(vector<int> &nums, int k) {
    sort(nums.rbegin(), nums.rend());
    print(nums);
    return nums[k - 1];
}