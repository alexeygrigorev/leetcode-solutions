#include <vector>

using namespace std;

struct MinIndexPair {
    int min_value;
    int index;
    MinIndexPair(int min_value, int index) : min_value(min_value), index(index) {};
};

class MinSegmentTree {
private:
    int size;
    MinIndexPair *values;
    MinIndexPair &combine(MinIndexPair &left, MinIndexPair &right);
    void build(vector<int> &heights, int idx, int from, int to);
public:
    MinSegmentTree(vector<int> &heights);
    MinIndexPair &min(int idx, int query_from, int query_to, int segment_from, int segment_to);
    int find_min_index(int from, int to);
};

class MaxHistRectangleSolution {
public:
    int largest_area_naive(vector<int> &heights);
    int largest_area_naive2(vector<int> &heights);
    int largest_area_stack(vector<int> &heights);
    int largest_area_recursive(vector<int> &heights, MinSegmentTree &st, int left, int right);
    int largest_area_segment_tree(vector<int> &heights);
    int largestRectangleArea(vector<int> &heights);
};