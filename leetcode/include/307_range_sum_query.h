#include <vector>
#include "segment_tree.h"

using namespace std;

class RangeSumArray {
    SumSegmentTree *st;
public:
    RangeSumArray(vector<int> nums);
    void update(int i, int val);
    int sumRange(int i, int j);
};
