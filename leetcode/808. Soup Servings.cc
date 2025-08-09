// 2025-08-08
// Refer to the solutions
class Solution {
 public:
  double soupServings(int n) {
    int m = ceil(n / 25.);
    unordered_map<int, unordered_map<int, double>> dp;
    dp[0][0] = .5;

    auto cal = [&](int m, int n) {
      double acc = 0;
      for (int i = 0; i < 4; ++i) {
        acc += dp[max(0, m - 4 + i)][max(0, n - i)];
      }
      return acc / 4;
    };

    for (int i = 1; i <= m; ++i) {
      dp[0][i] = 1;
      for (int j = 1; j <= i; ++j) {
        dp[i][j] = cal(i, j);
        dp[j][i] = cal(j, i);
      }
      if (abs(1 - dp[i][i]) < 1e-5) {
        return dp[i][i];
      }
    }

    return dp[m][m];
  }
};
