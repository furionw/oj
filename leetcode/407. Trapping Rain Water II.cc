// Copyright 2016 Qi Wang
// Date: 2016-11-02
class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    if (heightMap.size() <= 2 || heightMap[0].size() <= 2) return 0;
    size_t m = heightMap.size(), n = heightMap[0].size();
    int leftmost[m][n], rightmost[m][n], topmost[m][n], botmost[m][n];
    for (int i = 0; i < m; ++i)
      for (int j = 0, max = 0; j < n; ++j) {
        leftmost[i][j] = max;
        max = ::max(max, heightMap[i][j]);
      }
    for (int i = 0; i < m; ++i)
      for (int j = n - 1, max = 0; j >= 0; --j) {
        rightmost[i][j] = max;
        max = ::max(max, heightMap[i][j]);
      }
    for (int j = 0; j < n; ++j)
      for (int i = 0, max = 0; i < m; ++i) {
        topmost[i][j] = max;
        max = ::max(max, heightMap[i][j]);
      }
    for (int j = 0; j < n; ++j)
      for (int i = m - 1, max = 0; i >= 0; --i) {
        botmost[i][j] = max;
        max = ::max(max, heightMap[i][j]);
      }
    int res = 0;
    for (size_t i = 1; i < m; ++i)
      for (size_t j = 1; j < n; ++j) {
        int bound = ::min({leftmost[i][j], rightmost[i][j],
            topmost[i][j], botmost[i][j]});
        if (bound > heightMap[i][j]) res += bound - heightMap[i][j];
      }
    return res;
  }
};
