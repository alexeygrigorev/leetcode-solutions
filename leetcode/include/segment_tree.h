#include <vector>

using namespace std;

class SumSegmentTree {
private:
    int size;
    vector<int> values;

    int left_child(int idx);
    int right_child(int idx);
    void build(vector<int> &nums, int node_idx, int from, int to);
    int do_sum(int node_idx, int from, int to, int segment_start, int segment_end);
    void do_update(int node_idx, int from, int to, int i, int val);
public:
    SumSegmentTree(vector<int> &nums);
    int sum(int from, int to);
    void update(int i, int val);
};