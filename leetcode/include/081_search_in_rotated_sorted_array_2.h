#include <vector>

using namespace std;

class SearchRotatedSortedArray2Solution {
public:
    bool search(vector<int>& nums, int target);

private:
    bool find_sequential(vector<int> &nums, int target);
    bool bin_search(vector<int> &nums, int t, int start, int end);
    int find_pivot(vector<int> nums, int start, int end);
    int pivoted_search(vector<int> nums, int target);
};