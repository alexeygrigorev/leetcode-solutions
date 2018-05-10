#include <vector>

using namespace std;

class SearchRotatedSortedArray2Solution {
public:
    bool search(vector<int>& nums, int target);

private:
    bool find_sequential(vector<int> &nums, int target);
    bool rotated_search(vector<int> &nums, int target, int start, int end);
};