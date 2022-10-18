// Date: 2022-10-16
class Solution {
 public:
  int numberOfWays(int startPos, int endPos, int k) {
    if (startPos > endPos) {
      swap(startPos, endPos);
    }
    endPos -= startPos;
    if (endPos > k) {
      return 0;
    }
    vector<vector<int>> dp(
      2 * k + 1,
      vector<int>(k + 1, 0)
    );
    dp[k][0] = 1;
    for (size_t t = 1; t <= k; ++t) {
      for (int i = 0; i < dp.size(); ++i) {
        if (i > 0) {
          dp[i][t] = (dp[i][t] + dp[i - 1][t - 1]) % int(1e9 + 7);
        }
        if (i + 1 < dp.size()) {
          dp[i][t] = (dp[i][t] + dp[i + 1][t - 1]) % int(1e9 + 7);
        }
      }
    }
    return dp[endPos + k].back();
  }
};
