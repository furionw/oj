// Copyright 2017 Qi Wang
// Date: 2017-02-16
// Refer to: https://discuss.leetcode.com/topic/22580/ac-java-solution-without-extra-space
// O(nk) time, O(1) space
class Solution {
 public:
  int minCostII(vector<vector<int>>& costs) {
    if (costs.empty() || costs[0].empty()) return 0;
    int min1 = -1, min2 = -1;
    for (int i = 0; i < costs.size(); ++i) {
      int temp1 = min1, temp2 = min2;
      min1 = min2 = -1;
      for (int j = 0; j < costs[i].size(); ++j) {
        if (j != temp1) {
          costs[i][j] += temp1 < 0 ? 0 : costs[i - 1][temp1];
        } else {
          costs[i][j] += temp2 < 0 ? 0 : costs[i - 1][temp2];
        }
        if (min1 < 0 || costs[i][j] < costs[i][min1]) {
          min2 = min1, min1 = j;
        } else if (min2 < 0 || costs[i][j] < costs[i][min2]) {
          min2 = j;
        }
      }
    }
    return costs.back()[min1];
  }
};

// Date: 2017-02-16
// O(nk^2) time
class Solution {
 public:
  int minCostII(vector<vector<int>>& costs) {
    if (costs.empty() || costs[0].empty()) return 0;
    int n = costs.size(), k = costs[0].size();
    vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
    copy(costs[0].begin(), costs[0].end(), dp[0].begin());
    for (size_t i = 1; i < n; ++i) {
      for (int color = 0; color < k; ++color) {
        for (int prev_color = 0; prev_color < k; ++prev_color)
          if (color != prev_color)
            dp[i][color] = min(dp[i][color], dp[i - 1][prev_color]);
        dp[i][color] += costs[i][color];
      }
    }
    return *min_element(dp.back().begin(), dp.back().end());
  }
};
