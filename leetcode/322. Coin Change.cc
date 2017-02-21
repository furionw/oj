// Copyright 2017 Qi Wang
// Date: 2017-02-19
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int coin : coins)
      for (int i = 0; i + coin <= amount; ++i)
        dp[i + coin] = min(dp[i + coin], dp[i] + 1);
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

// Date: 2016-10-08
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int coin : coins)
      for (int i = 0; i + coin <= amount; ++i)
        if (dp[i] != INT_MAX)
          dp[i + coin] = min(dp[i + coin], dp[i] + 1);
    return dp[amount] != INT_MAX ? dp[amount] : -1;
  }
};
