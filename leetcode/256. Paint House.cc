// Copyright 2017 Qi Wang
// Date: 2017-02-16
class Solution {
 public:
  int minCost(vector<vector<int>>& costs) {
    vector<vector<int>> dp(costs.size() + 1, vector<int>(3, 0));
    int prev[3][2] = {{1, 2}, {0, 2}, {0, 1}};
    for (size_t i = 0; i < costs.size(); ++i)
      for (int color = 0; color <= 2; ++color)
        dp[i + 1][color] = min(dp[i][prev[color][0]], dp[i][prev[color][1]])
            + costs[i][color];
    return *min_element(dp[costs.size()].begin(), dp[costs.size()].end());
  }
};
