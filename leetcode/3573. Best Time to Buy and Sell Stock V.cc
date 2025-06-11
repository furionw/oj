// 2025-06-10
class Solution {
 public:
  long long maximumProfit(vector<int>& ps, int k) {
    long long result = 0;

    vector<vector<long long>> dp(k + 1, vector<long long>(3, numeric_limits<int>::min()));
    for (int i = 0; i < dp.size(); ++i) {
      dp[i][kClose] = 0;
    }

    for (int i = 0; i < ps.size(); ++i) {
      // i = 0 -> 1 day, 1 transcation
      // i = 1 -> 2 days, 1 transcation
      // i = 2 -> 3 days, 2 transcation
      // i = 3 -> 4 days, 2 transcation
      int t = min(i / 2 + 1, k);
      for (int j = t; j >= 1; --j) {
        dp[j][kClose] = max(dp[j][kClose], dp[j - 1][kClose]);
        dp[j][kClose] = max(dp[j][kClose], dp[j][kHold] + ps[i]);
        dp[j][kClose] = max(dp[j][kClose], dp[j][kBorrow] - ps[i]);
        result = max(result, dp[j][kClose]);

        dp[j][kBorrow] = max(dp[j][kBorrow], dp[j - 1][kClose] + ps[i]);
        dp[j][kHold] = max(dp[j][kHold], dp[j - 1][kClose] - ps[i]);
      }
    }

    return result;
  }

 private:
  constexpr static int kBorrow = 0, kClose = 1, kHold = 2;
};
