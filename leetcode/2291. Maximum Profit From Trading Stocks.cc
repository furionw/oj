// 2025-07-14
class Solution {
 public:
  int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
    vector<int> dp(budget + 1, 0);
    int n = present.size();
    for (int i = 0; i < n; ++i) {
      int cost = present[i];
      int profit = max(0, future[i] - cost);
      for (int j = budget; j - cost >= 0; --j) {
        dp[j] = max(dp[j], dp[j - cost] + profit);
      }
    }
    return dp[budget];
  }
};
