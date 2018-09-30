#include "123_best_time_buy_stock_3.h"

int BestTimeBuyStock3Solution::calc_max_profit(vector<int> &prices, int from, int to) {
    // solution to 121
    if (to - from <= 1) {
        return 0;
    }

    int min_p = prices[from];
    int max_profit = 0;

    for (int i = from + 1; i < to; i++) {
        int p = prices[i];
        if (p < min_p) {
            min_p = p;
            continue;
        }
        int profit = p - min_p;
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}

int BestTimeBuyStock3Solution::max_profit_linear_split(vector<int> &prices) {
    // split the array into two parts and apply solution to 121 to each part
    // this is O(n^2)
    int n = prices.size();

    if (n <= 1) {
        return 0;
    }

    int profit = calc_max_profit(prices, 0, n);

    for (int i = 2; i < n; i++) {
        int profit_1 = calc_max_profit(prices, 0, i);
        int profit_2 = calc_max_profit(prices, i, n);
        profit = max(profit, profit_1 + profit_2);
    }

    return profit;
}

int BestTimeBuyStock3Solution::maxProfit(vector<int> &prices) {
    return max_profit_linear_split(prices);
}
