#include <string>
#include <vector>
#include <algorithm>
#include "debug.h"
#include "heap.h"

using namespace std;

class MedianFinderSolution {
public:
    MedianFinderSolution();
    void addNum(int num);
    double findMedian();

private:
    Heap* left_max_heap;
    Heap* right_min_heap;
    void rebalance();
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */