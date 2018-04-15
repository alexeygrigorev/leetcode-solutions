#include <string>
#include <vector>
#include <algorithm>

#include "215_kth_element.h"
#include "debug.h"


using namespace std;

int KthLargestSolution::findKthLargest(vector<int> &nums, int k) {
    // TODO
    sort(nums.begin(), nums.end());
    print(nums);
    return nums[k];
}
