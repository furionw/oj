// Date: 2022-11-15
// Received hint that this can be solved by dp[high + 1]
class Solution {
 public:
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> dp(high + 1, 0);
    dp[zero] = 1;
    dp[one] = dp[one] + 1;
    for (int i = 0; i <= high; ++i) {
      int prev = i - zero;
      if (prev >= 0) {
        dp[i] += dp[prev];
      }
      prev = i - one;
      if (prev >= 0) {
        dp[i] += dp[prev];
      }
      dp[i] %= int(1e9 + 7);
    }
    int res = 0;
    for (int i = low; i <= high; ++i) {
      res += dp[i];
      res %= int(1e9 + 7);
    }
    return res;
  }
};
