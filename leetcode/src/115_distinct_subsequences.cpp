#include "115_distinct_subsequences.h"

int DistinctSubsequencesSolution::count_recursive_naive(string s, string t) {
    if (t.empty()) {
        return 1;
    }

    if (s.size() < t.size()) {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        if (t[0] == s[i]) {
            count = count + count_recursive_naive(s.substr(i + 1), t.substr(1));
        }
    }

    return count;
}

int DistinctSubsequencesSolution::count_memo(string &s, string &t,
        int pos_s, int pos_t, vector<vector<int>> &memo) {
    int t_size = t.size();
    int s_size = s.size();

    int t_remaining = t_size - pos_t;
    int s_remaining = s_size - pos_s;

    if (t_remaining <= 0) {
        return 1;
    }

    if (s_remaining < t_remaining) {
        return 0;
    }

    if (memo[pos_s][pos_t] != -1) {
        return memo[pos_s][pos_t];
    }

    int count = 0;

    for (int i = pos_s; i < s_size - t_remaining + 1; i++) {
        if (t[pos_t] == s[i]) {
            count = count + count_memo(s, t, i + 1, pos_t + 1, memo);
        }
    }

    memo[pos_s][pos_t] = count;
    return count;
}

int DistinctSubsequencesSolution::num_distinct_memo(string &s, string &t) {
    vector<vector<int>> memo(s.size(), vector<int>(t.size(), -1));
    return count_memo(s, t, 0, 0, memo);
}

int DistinctSubsequencesSolution::num_distinct_dp(string &s, string &t) {
    vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));
    fill(dp[0].begin(), dp[0].end(), 1);

    for (int i = 1; i <= t.size(); i++) {
        for (int j = 1; j <= s.size(); j++) {
            if (t[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[t.size()][s.size()];
}

int DistinctSubsequencesSolution::numDistinct(string s, string t) {
    return num_distinct_dp(s, t);
}
