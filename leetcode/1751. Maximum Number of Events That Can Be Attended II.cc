// 2025-07-09
class Solution {
 public:
  int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end());
    int n = events.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    dp[n - 1][1] = events[n - 1][2];
    for (int i = n - 2; i >= 0; --i) {
      const auto& e = events[i];
      for (int j = 1; j <= k; ++j) {
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        dp[i][j] = max(dp[i][j], e[2]);
        auto it = upper_bound(events.begin() + i + 1, events.end(), e[1],
            [](int end, const auto& e) {
              return end < e[0];
            });
        if (it != events.end()) {
          dp[i][j] = max(dp[i][j], dp[it - events.begin()][j - 1] + e[2]);
        }
      }
    }
    return dp[0][k];
  }
};
