#include "137_single_number_2.h"
#include <unordered_map>

int SingleNumber2Solution::single_number_hashmap(vector<int> &nums) {
    unordered_map<int, int> cnt;
    for (int num : nums) {
        cnt[num]++;

        if (cnt[num] == 3) {
            cnt.erase(num);
        }
    }

    return cnt.begin()->first;
}

int SingleNumber2Solution::single_number_bits(vector<int> &nums) {
    return 0;
}

int SingleNumber2Solution::singleNumber(vector<int> &nums) {
    return single_number_hashmap(nums);
}
