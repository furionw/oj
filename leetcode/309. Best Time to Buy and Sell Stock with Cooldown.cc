// Copyright 2016 Qi Wang
// Method 1
// Date: 2016-11-23
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    size_t n = prices.size();
    int buys[n], sells[n];
    buys[0] = -prices[0];
    buys[1] = max(-prices[0], -prices[1]);
    sells[0] = 0;
    sells[1] = max(0, prices[1] - prices[0]);
    for (size_t i = 2; i < n; ++i) {
      // buy
      buys[i] = max(buys[i - 1], sells[i - 2] - prices[i]);
      // sell
      sells[i] = max(sells[i - 1], buys[i - 1] + prices[i]);
    }
    return sells[n - 1];
  }
};

// Method 2
// Date: 2016-11-23
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    size_t n = prices.size();
    int dp[n][3];
    dp[0][0] = -prices[0];
    dp[0][1] = dp[0][2] = 0;
    for (size_t i = 1; i < n; ++i) {
      // buy
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
      // sell
      dp[i][1] = dp[i - 1][0] + prices[i];
      // CD
      dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
    }
    return max(dp[n - 1][1], dp[n - 1][2]);
  }
};

