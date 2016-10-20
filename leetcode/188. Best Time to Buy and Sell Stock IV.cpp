// Copyright 2016 Qi Wang
// Reference: http://liangjiabin.com/blog/2015/04/leetcode-best-time-to-buy-and-sell-stock.html
// I think we can make a transaction within a day -- buy and sell stock in the same day
// Date: 2016-10-06
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    if (2 * k >= prices.size()) {
      int prof = 0;
      for (int i = 1; i < prices.size(); ++i)
        prof += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
      return prof;
    } else {
      vector<int> local(k + 1, 0), global(k + 1, 0);
      for (size_t i = 1; i < prices.size(); ++i) {
        int diff = prices[i] - prices[i - 1];
        for (int j = 1; j <= k; ++j) {
          local[j] = max(global[j - 1], local[j] + diff);
          global[j] = max(global[j], local[j]);
        }
      }
      return global.back();
    }
  }
};
