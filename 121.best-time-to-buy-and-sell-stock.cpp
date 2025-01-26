// @leet start
#include <vector>
using std::vector;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int max_profit = 0;
    int buy_idx = 0, sell_idx = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] < prices[buy_idx]) {
        buy_idx = i;
      } else if (prices[i] - prices[buy_idx] > max_profit) {
        max_profit = prices[i] - prices[buy_idx];
        sell_idx = i;
      }
    }
    return max_profit;
  }
};
// @leet end
