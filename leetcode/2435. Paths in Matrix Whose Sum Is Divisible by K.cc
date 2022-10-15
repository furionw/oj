// Date: 2022-10-08
class Solution {
 public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(n, vector<int>(k, 0))
    );
    int acc = 0;
    for (int i = 0; i < m; ++i) {
      acc += grid[i][0];
      dp[i][0][ acc % k ] = 1;
    }
    acc = 0;
    for (int j = 0; j < n; ++j) {
      acc += grid[0][j];
      dp[0][j][ acc % k ] = 1;
    }
    int mod = 1e9 + 7;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        for (int x = 0; x < k; ++x) {
          int idx = (x + grid[i][j]) % k;
          dp[i][j][idx] = (dp[i][j][idx] + dp[i - 1][j][x]) % mod;
          dp[i][j][idx] = (dp[i][j][idx] + dp[i][j - 1][x]) % mod;
        }
      }      
    }
    return dp[m - 1][n - 1][0];
  }
};