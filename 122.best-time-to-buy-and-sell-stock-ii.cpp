// @leet start
#include <vector>
using std::vector;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int max_profit = 0;
    int tmp_max = 0;
    int buy_idx = 0, sell_idx = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] > prices[sell_idx]) {
        sell_idx = i;
      } else {
        max_profit += prices[sell_idx] - prices[buy_idx];
        buy_idx = i;
        sell_idx = i;
      }
    }
    max_profit += prices[sell_idx] - prices[buy_idx];
    return max_profit;
  }
};
// @leet end
