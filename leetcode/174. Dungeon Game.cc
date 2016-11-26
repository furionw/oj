// Copyright 2016 Stephen Wong
// http://www.cnblogs.com/grandyang/p/4233035.html
// Date: 2016-11-26
class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = dungeon.size(), m = dungeon[0].size();
    // Add an extra element in dp array to eliminate branch in the inner loop.
    int dp[m + 1];
    // DP init
    dp[m] = INT_MAX;
    dp[m - 1] = max(1, -dungeon[n - 1][m - 1] + 1);
    for (int j = m - 2; j >= 0; --j)
      dp[j] = max(1, dp[j + 1] - dungeon[n - 1][j]);
    // dp deduct
    for (int i = n - 2; i >= 0; --i)
      for (int j = m - 1; j >= 0; --j)
        dp[j] = max(1, min(dp[j], dp[j + 1]) - dungeon[i][j]);
    return dp[0];
  }
};

// TLE
// Date: 2016-09-29
class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int res = INT_MAX;
    calculateMinimumHP(dungeon, 0, 0, 1, 1, res);
    return res;
  }

 private:
  void calculateMinimumHP(const vector<vector<int>>& dungeon, int i, int j,
      int preCost, int maxCost, int& res) {
    int curCost = preCost - dungeon[i][j];
    // prune
    if (curCost >= res) return;
    maxCost = max(maxCost, curCost);
    if (i + 1== dungeon.size() && j + 1 == dungeon[0].size()) {
      // We get the princess
      res = min(res, maxCost);
    } else {
      if (i + 1 < dungeon.size())
        calculateMinimumHP(dungeon, i + 1, j, curCost, maxCost, res);
      if (j + 1 < dungeon[0].size())
        calculateMinimumHP(dungeon, i, j + 1, curCost, maxCost, res);
    }
  }
};
