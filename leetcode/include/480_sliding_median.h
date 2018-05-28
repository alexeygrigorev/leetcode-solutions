#include <vector>
#include <set>
#include <map>

using namespace std;

class IntMultiset {
public:
    IntMultiset();

    void add(int el);
    bool remove(int el);

    int min();
    int pop_min();
    int max();
    int pop_max();
    int size();

private:
    int _size;
    map<int, int> internal_map;
    void decrement(pair<const int, int> &pair);

};

class SlidingMedianFinder {
public:
    SlidingMedianFinder(vector<int> &nums, int k);
    vector<double> run();

private:
    int k;
    vector<int> &nums;

    IntMultiset left_max_tree;
    IntMultiset right_min_tree;

    void remove_and_add(int to_remove, int to_add);
    void remove_element(int el);
    void add_element(int el);

    double current_median();
};

class SlidingMedianSolution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k);
};