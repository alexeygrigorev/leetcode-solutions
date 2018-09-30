#include <vector>

using namespace std;

class BestTimeBuyStock3Solution {
public:
    int calc_max_profit(vector<int> &prices, int from, int to);
    int max_profit_linear_split(vector<int> &prices);
    int maxProfit(vector<int> &prices);
};