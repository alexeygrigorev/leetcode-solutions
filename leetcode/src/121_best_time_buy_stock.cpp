#include "121_best_time_buy_stock.h"

int BestTimeBuyStockSolution::maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) {
        return 0;
    }

    int max_profit = 0;
    int min = prices[0];

    for (int i = 1; i < prices.size(); i++) {
        int el = prices[i];
        if (el < min) {
            min = el;
            continue;
        }

        int profit = el - min;
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}
