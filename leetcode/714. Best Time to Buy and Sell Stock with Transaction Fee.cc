// Copyright 2017 Qi Wang
// Date: 2017-11-02
// Case 1: [], ?
// Case 2: [1, 5], 1
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    if (prices.size() <= 1) return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][1] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp.back()[0];
  }
};

// Date: 2017-10-22
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    if (prices.size() < 2) return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][1] = -prices[0] - fee;
    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
    }
    return dp.back()[0];
  }
};
