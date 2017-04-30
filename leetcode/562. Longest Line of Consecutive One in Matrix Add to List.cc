// Copyright 2017 Qi Wang
// Date: 2017-04-29
class Solution {
 public:
  int longestLine(vector<vector<int>>& M) {
    if (M.empty() || M[0].empty()) return 0;
    size_t m = M.size(), n = M[0].size();
    vector<int> verticals(n, 0), diags(n, 0), anti_diags(n, 0);
    int result = 0;
    for (int i = 0; i < m; ++i) {
      int horizontal = 0;
      for (int j = 0; j < n; ++j) {
        if (1 == M[i][j]) {
          result = max(result, ++horizontal);
          result = max(result, ++verticals[j]);
          result = max(result, diags[j] = j + 1 < n ? diags[j + 1] + 1 : 1);
        } else {
          diags[j] = verticals[j] = horizontal = 0;
        }
      }
      for (int j = n - 1; j >= 0; --j) {
        if (1 == M[i][j]) {
          result = max(result, anti_diags[j] = j > 0 ? anti_diags[j - 1] + 1 : 1);
        }  else {
          anti_diags[j] = 0;
        }
      }
    }
    return result;
  }
};
