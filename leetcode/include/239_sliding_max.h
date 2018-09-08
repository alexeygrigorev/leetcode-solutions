#include <vector>
#include <map>

using namespace std;


class MaxWindow {
    map<int, int> counts;
public:
    void erase(int el);
    void insert(int el);
    int max();
};

class SlidingMaxSolution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k);
};