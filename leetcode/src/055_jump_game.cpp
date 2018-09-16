#include "055_jump_game.h"

bool JumpGameSolution::can_reach_recursive(vector<int> &nums, int from, int to, vector<int> &memo) {
    if (memo[from] != -1) {
        return (bool) memo[from];
    }

    int pos_max_jump = from + nums[from];
    if (pos_max_jump >= to) {
        memo[from] = true;
        return true;
    }

    for (int i = pos_max_jump; i >= from + 1; i--) {
        if (can_reach_recursive(nums, i, to, memo)) {
            memo[i] = true;
            return true;
        } else {
            memo[i] = false;
        }
    }

    memo[from] = false;
    return false;
}

bool JumpGameSolution::can_jump_recursive(vector<int> &nums) {
    int n = nums.size();
    vector<int> memo(n, -1);
    return can_reach_recursive(nums, 0, n - 1, memo);
}

bool JumpGameSolution::can_jump_linear(vector<int> &nums) {
    int n = nums.size();
    int max_index = 0;

    for (int i = 0; i < n && i <= max_index; i++) {
        int next = i + nums[i];
        if (max_index < next) {
            max_index = next;
        }
    }

    return max_index >= n - 1;
}

bool JumpGameSolution::canJump(vector<int> &nums) {
    return can_jump_linear(nums);
}
