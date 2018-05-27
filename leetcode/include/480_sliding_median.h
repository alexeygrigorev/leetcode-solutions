#include <vector>
#include <set>

using namespace std;

class SlidingMedianFinder {
public:
    SlidingMedianFinder(vector<int> &nums, int k);
    vector<double> run();

private:
    int k;
    vector<int> &nums;

    set<int, greater<int>> left_max_tree;
    set<int, less<int>> right_min_tree;

    double current_median();
};

class SlidingMedianSolution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k);
};