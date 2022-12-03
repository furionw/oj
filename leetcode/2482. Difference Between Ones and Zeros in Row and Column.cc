// Date: 2022-12-01
class Solution {
 public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    vector<int> onesRow(m, 0), zerosRow(m, 0);
    for (int i = 0; i < m; ++i) {
      onesRow[i] = accumulate(grid[i].begin(), grid[i].end(), 0);
      zerosRow[i] = m - onesRow[i];
    }

    vector<int> onesCol(n, 0), zerosCol(n, 0);
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        onesCol[j] += grid[i][j];
      }
      zerosCol[j] = n - onesCol[j];
    }
      
    vector<vector<int>> diff(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        diff[i][j] = onesRow[i] - zerosRow[i] + onesCol[j] - zerosCol[j];
      }
    }
    return diff;
  }
};
