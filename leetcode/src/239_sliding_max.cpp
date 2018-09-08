#include "239_sliding_max.h"

void MaxWindow::erase(int el) {
    counts[el]--;
    if (counts[el] <= 0) {
        counts.erase(el);
    }
}

void MaxWindow::insert(int el) {
    counts[el]++;
}

int MaxWindow::max() {
    auto it = counts.rbegin();
    return it->first;
}


vector<int> SlidingMaxSolution::maxSlidingWindow(vector<int> &nums, int k) {
    if (k <= 1) {
        return nums;
    }

    vector<int> out;
    MaxWindow window;

    for (int i = 0; i < k; i++) {
        window.insert(nums[i]);
    }

    int m = window.max();
    out.push_back(m);

    int n = nums.size();
    for (int i = k; i < n; i++) {
        window.erase(nums[i - k]);
        window.insert(nums[i]);
        int m = window.max();
        out.push_back(m);
    }

    return out;
}
