#include "480_sliding_median.h"

using namespace std;

IntMultiset::IntMultiset() {
    _size = 0;
}

void IntMultiset::add(int el) {
    internal_map[el]++;
    _size++;
}

int IntMultiset::min() {
    pair<const int, int> &pair = *internal_map.begin();
    return pair.first;
}

int IntMultiset::pop_min() {
    pair<const int, int> &pair = *internal_map.begin();
    decrement(pair);
    return pair.first;
}

bool IntMultiset::remove(int el) {
    const map<int, int>::iterator &it = internal_map.find(el);
    if (it == internal_map.end()) {
        return false;
    }

    pair<const int, int> &p = *it;
    decrement(p);
    return true;
}

void IntMultiset::decrement(pair<const int, int> &pair) {
    int key = pair.first;
    int cnt = pair.second;

    if (cnt == 1) {
        internal_map.erase(key);
    } else {
        internal_map[key]--;
    }

    _size--;
}

int IntMultiset::max() {
    pair<const int, int> &pair = *internal_map.rbegin();
    return pair.first;
}

int IntMultiset::pop_max() {
    pair<const int, int> &pair = *internal_map.rbegin();
    decrement(pair);
    return pair.first;
}

int IntMultiset::size() {
    return _size;
}

vector<double> SlidingMedianSolution::medianSlidingWindow(vector<int> &nums, int k) {
    if (k == 1) {
        vector<double> result;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back((double) nums[i]);
        }
        return result;
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
        left_max_tree.add(nums[i]);
    }

    while (left_max_tree.size() > right_min_tree.size()) {
        int from_left = left_max_tree.pop_max();
        right_min_tree.add(from_left);
    }

    double median = current_median();
    result.push_back(median);

    for (int i = k; i < nums.size(); i++) {
        int prev = nums[i - k];
        int cur = nums[i];

        remove_and_add(prev, cur);
        median = current_median();
        result.push_back(median);
    }

    return result;
}

void SlidingMedianFinder::add_element(int el) {
    right_min_tree.add(el);
    int from_right = right_min_tree.pop_min();
    left_max_tree.add(from_right);

    while (left_max_tree.size() > right_min_tree.size()) {
        int from_left = left_max_tree.pop_max();
        right_min_tree.add(from_left);
    }
}


void SlidingMedianFinder::remove_and_add(int to_remove, int to_add) {
    if (to_remove == to_add) {
        return;
    }
    remove_element(to_remove);
    add_element(to_add);
}

void SlidingMedianFinder::remove_element(int el) {
    if (right_min_tree.remove(el)) {
        return;
    }

    left_max_tree.remove(el);
}

double SlidingMedianFinder::current_median() {
    if (k % 2 == 0) {
        int left = left_max_tree.max();
        int right = right_min_tree.min();
        return left * 0.5 + right * 0.5;
    } else {
        return right_min_tree.min();
    }
}