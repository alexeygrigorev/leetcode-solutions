#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include "debug.h"

using namespace std;

class MedianFinderSolution {
public:
    MedianFinderSolution();
    void addNum(int num);
    double findMedian();

private:
    priority_queue<int, vector<int>, greater<int>> left_max_heap;
    priority_queue<int, vector<int>, less<int>> right_min_heap;
};