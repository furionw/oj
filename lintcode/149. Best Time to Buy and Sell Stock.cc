// Copyright 2017 Qi Wang
// Date: 2017-10-11
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) return 0;
    int max_profit = 0;
    int lowest_price = prices.front();
    for (int i = 1; i < prices.size(); ++i) {
      max_profit = max(max_profit, prices[i] - lowest_price);
      lowest_price = min(lowest_price, prices[i]);
    }
    return max_profit;
  }
};
