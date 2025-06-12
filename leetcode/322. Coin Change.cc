// 2025-06-11
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int coin : coins) {
      for (int i = 0; i + coin <= amount; ++i) {
        if (dp[i] == INT_MAX) {
          continue;
        }
        dp[i + coin] = min(dp[i + coin], dp[i] + 1);
      }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

// 2025-06-11
// Not helpful to introduce "coins2" because we need to loop through
// [1, amount] anyway
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<pair<int, int>> coins2;
    for (int c : coins) {
      for (int num = 1; c <= amount; c = c * 2, num = num * 2) {
        coins2.emplace_back(c, num);
      }
    }

    int inf = 1e9;
    vector<int> dp(amount + 1, inf);
    dp[0] = 0;
    for (auto [c, num]: coins2) {
      for (int i = amount; i >= 1; --i) {
        int prev = i - c;
        if (prev < 0) {
          continue;
        }
        dp[i] = min(dp[i], dp[prev] + num);
      }
    }
    return dp[amount] == inf? -1 : dp[amount];
  }
};

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
