#include <string>
#include "295_median.h"

using namespace std;

void MedianFinderSolution::addNum(int num) {
    right_min_heap.push(num);

    int min_from_right = right_min_heap.top();
    right_min_heap.pop();
    left_max_heap.push(min_from_right);

    if (left_max_heap.size() > right_min_heap.size()) {
        int max_from_left = left_max_heap.top();
        left_max_heap.pop();
        right_min_heap.push(max_from_left);
    }
}

double MedianFinderSolution::findMedian() {
    int size_left = left_max_heap.size();
    int size_right = right_min_heap.size();

    if (size_left < size_right) {
        return right_min_heap.top();
    }

    int l = left_max_heap.top();
    int r = right_min_heap.top();
    return l * 0.5 + r * 0.5;
}

MedianFinderSolution::MedianFinderSolution() {
}
