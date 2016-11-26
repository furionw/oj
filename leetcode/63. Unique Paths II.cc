// Copyright 2016 Qi Wang
// Date: 2016-11-26
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    int dp[m + 1];
    // dp init
    dp[0] = 0;
    // First row
    dp[1] = 1 - obstacleGrid[0][0];
    for (int j = 2; j <= m; ++j)
      dp[j] = min(dp[j - 1], 1 - obstacleGrid[0][j - 1]);
    // Following rows
    for (int i = 1; i < n; ++i)
      for (int j = 1; j <= m; ++j)
        dp[j] = obstacleGrid[i][j - 1] ? 0 : dp[j - 1] + dp[j];
    return dp[m];
  }
};

// Date: 2014-07
class Solution 
{
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
  {
    auto vt = obstacleGrid; // just declare a virable
    vt[0][0] = 1 - obstacleGrid[0][0];

    for (int i = 1; i < vt[0].size(); ++ i)
    {
      vt[0][i] = (1-obstacleGrid[0][i-1]) * vt[0][i-1];
    }
    for (int i = 1; i < vt.size(); ++ i)
    {
      vt[i][0] = (1-obstacleGrid[i-1][0]) * vt[i-1][0];
    }
    for (int i = 1; i < vt.size(); ++ i)
    {
      for (int j = 1; j < vt[0].size(); ++ j)
      {
        vt[i][j] = (1-obstacleGrid[i-1][j])*vt[i-1][j] + (1-obstacleGrid[i][j-1])*vt[i][j-1];
      }
    }

    return (1-obstacleGrid[vt.size()-1][vt[0].size()-1]) * vt[vt.size()-1][vt[0].size()-1];
  }
};