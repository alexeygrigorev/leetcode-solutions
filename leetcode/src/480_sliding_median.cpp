#include <vector>
#include <cstdio>
#include "480_sliding_median.h"

using namespace std;

vector<double> SlidingMedianSolution::medianSlidingWindow(vector<int> &nums, int k) {
    if (k == 1) {
        // TODO
    }

    SlidingMedianFinder *solution = new SlidingMedianFinder(nums, k);
    vector<double> result = solution->run();
    delete solution;
    return result;
}


SlidingMedianFinder::SlidingMedianFinder(vector<int> &nums, int k) : nums(nums), k(k) {
}

vector<double> SlidingMedianFinder::run() {
    vector<double> result;

    for (int i = 0; i < k; i++) {
        printf("%d\n", nums[i]);
        right_min_tree.insert(nums[i]);
    }

    int left_size = 0;
    int right_size = k;

    while (left_size < right_size) {
        int from_right = *right_min_tree.begin();
        right_min_tree.erase(from_right);
        left_max_tree.insert(from_right);
        left_size++;
        right_size--;
    }

    double median = current_median();
    printf("%f\n", median);
    result.push_back(median);

    for (int i = k; i < nums.size(); i++) {
        int prev = nums[i - k];
        int cur = nums[i];
        printf("removing %d, adding %d\n", prev, cur);

        int left_removed = left_max_tree.erase(prev);
        left_size = left_size - left_removed;
        int right_removed = right_min_tree.erase(prev);
        right_size = right_size - right_removed;
        printf("removed %d from left, %d from right\n", left_removed, right_removed);

        right_min_tree.insert(cur);
        right_size++;

        printf("sizes: %d, %d\n", left_size, right_size);

        while (left_size < right_size) {
            int from_right = *right_min_tree.begin();
            right_min_tree.erase(from_right);
            left_max_tree.insert(from_right);
            left_size++;
            right_size--;
        }

        printf("sizes: %d, %d\n", left_size, right_size);

        double median = current_median();
        printf("median: %f\n", median);
        result.push_back(median);
    }

    return result;
}

double SlidingMedianFinder::current_median() {
    if (k % 2 == 0) {
        int l = *left_max_tree.begin();
        int r = *right_min_tree.begin();
        return l * 0.5 + r * 0.5;
    } else {
        return *left_max_tree.begin();
    }
}
