// 2025-06-10
// Refer to the Editorial
class Solution {
 public:
  int paintWalls(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    int sz = n + 1;
    vector<vector<int>> dp(sz, vector<int>(sz, 0));
    for (int j = 1; j <= n; ++j) {
      dp[n][j] = 1e9;
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int remain = 1; remain <= n; ++remain) {
        int paint = dp[i + 1][max(0, remain - time[i] - 1)] + cost[i];
        int dontPaint = dp[i + 1][remain];
        dp[i][remain] = min(paint, dontPaint);
      }
    }
    return dp[0][n];
  }
};
