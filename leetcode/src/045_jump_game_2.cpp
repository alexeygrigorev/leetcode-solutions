#include <climits>
#include <queue>
#include "045_jump_game_2.h"

int JumpGame2Solution::jump_slow(vector<int> &nums) {
    int n = nums.size();
    int to = n - 1;
    vector<int> sizes = vector<int>(n, INT_MAX);
    sizes[0] = 0;

    for (int from = 0; from < to; from++) {
        int max_jump = from + nums[from];
        if (max_jump > to) {
            max_jump = to;
        }

        int s = sizes[from] + 1;

        for (int i = from + 1; i <= max_jump; i++) {
            if (s < sizes[i]) {
                sizes[i] = s;
            }
        }
    }

    return sizes[to];
}

int JumpGame2Solution::jump_bfs(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
        return 0;
    }

    vector<int> dist(n, -1);
    vector<bool> visited(n, false);

    int start = 0;
    int target = n - 1;

    visited[start] = true;
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        int to = idx + nums[idx];
        if (to >= target) {
            return dist[idx] + 1;
        }

        for (int i = to; i > idx; i--) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            dist[i] = dist[idx] + 1;
            q.push(i);
        }
    }

    return dist[target];
}

int JumpGame2Solution::jump(vector<int> &nums) {
    return jump_bfs(nums);
}
