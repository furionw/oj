// Copyright 2017 Qi Wang
// Date: 2017-08-04
// O(nk) time, but the implementation on 2017-02-16 is more consie
class Solution {
 public:
  int minCostII(vector<vector<int>>& costs) {
    if (costs.empty()) return 0;
    if (!costs.empty() && costs[0].empty()) return -1;
    if (costs.size() > 1 && costs[0].size() <= 1) return -1;
    int n = costs.size(), k = costs[0].size();
    int min1 = 0, min2 = 0, min1_idx = -1;
    for (int i = 0; i < n; ++i) {
      int next_min1 = INT_MAX, next_min1_idx, next_min2 = INT_MAX;
      for (int j = 0; j < k; ++j) {
        if (j != min1_idx) {
          costs[i][j] += min1;
        } else {
          costs[i][j] += min2;
        }
        if (costs[i][j] < next_min1) {
          next_min2 = next_min1;
          next_min1 = costs[i][j];
          next_min1_idx = j;
        } else if (costs[i][j] < next_min2) {
          next_min2 = costs[i][j];
        }
      }
      min1 = next_min1;
      min1_idx = next_min1_idx;
      min2 = next_min2;
    }
    return *min_element(costs.back().begin(), costs.back().end());
  }
};

// Date: 2017-08-04
// O(nk^2) time
class Solution {
 public:
  int minCostII(vector<vector<int>>& costs) {
    if (costs.empty() || costs[0].empty()) return 0;
    int n = costs.size(), k = costs[0].size();
    vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
    for (int j = 0; j < k; ++j) {
      dp[0][j] = costs[0][j];
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        for (int q = 0; q < k; ++q) {
          if (j == q) continue;
          dp[i][j] = min(dp[i][j], dp[i - 1][q] + costs[i][j]);
        }
      }
    }
    return *min_element(dp.back().begin(), dp.back().end());
  }
};

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
