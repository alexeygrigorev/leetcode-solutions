#include <string>
#include "295_median.h"

using namespace std;

void MedianFinderSolution::addNum(int num) {
    printf("insert %d\n", num);

    if (left_max_heap->size() == 0) {
        left_max_heap->push(num);
        rebalance();
        return;
    }

    int m = left_max_heap->peek();
    if (num <= m) {
        left_max_heap->push(num);
    } else {
        right_min_heap->push(num);
    }

    rebalance();
}

double MedianFinderSolution::findMedian() {
    int size_left = left_max_heap->size();
    int size_right = right_min_heap->size();
    int size = size_left + size_right;

    if (size % 2 == 0) {
        printf("median is (%d + %d) / 2\n", left_max_heap->peek(), right_min_heap->peek());
        return 0.5 * (left_max_heap->peek() + right_min_heap->peek());
    } else {
        printf("median is %d\n", left_max_heap->peek());
        return left_max_heap->peek();
    }
}

void MedianFinderSolution::rebalance() {
    // should be either equal size
    // or the right should contain one more element

    int size_left = left_max_heap->size();
    int size_right = right_min_heap->size();
    int size = size_left + size_right;

    printf("heaps :\n");
    left_max_heap->print_content();
    right_min_heap->print_content();

}

MedianFinderSolution::MedianFinderSolution() {
    this->left_max_heap = Heap::max_heap();
    this->right_min_heap = Heap::min_heap();
}
