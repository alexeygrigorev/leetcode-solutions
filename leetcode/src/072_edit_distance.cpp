#include "072_edit_distance.h"

int EditDistanceSolution::min3(int a, int b, int c) {
    return min(a, min(b, c));
}

int EditDistanceSolution::minDistance(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();

    int dp[n1 + 1][n2 + 1];
    dp[0][0] = 0;

    for (int i = 1; i <= n1; i++) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= n2; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            int subst_cost = dp[i - 1][j - 1];
            if (word1[i - 1] != word2[j - 1]) {
                subst_cost = subst_cost + 1;
            }

            int del_cost = dp[i][j - 1] + 1;
            int ins_cost = dp[i - 1][j] + 1;

            dp[i][j] = min3(subst_cost, del_cost, ins_cost);
        }
    }

    return dp[n1][n2];
}