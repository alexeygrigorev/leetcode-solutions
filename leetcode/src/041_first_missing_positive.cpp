#include "041_first_missing_positive.h"

int FirstMissingPositiveSolution::firstMissingPositive(vector<int> &nums) {
    int len = nums.size();
    vector<bool> used(len, false);

    for (int num : nums) {
        if (num > 0) {
            used[num - 1] = true;
        }
    }

    for (int i = 0; i < len; i++) {
        if (used[i] == false) {
            return i + 1;
        }
    }

    return len + 1;
}
