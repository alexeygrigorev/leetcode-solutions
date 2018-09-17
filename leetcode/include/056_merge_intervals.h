#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class MergeIntervalsSolution {
public:
    vector<Interval> merge(vector<Interval> &intervals);
};