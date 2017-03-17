// Copyright 2017 Qi Wang
// Date: 2017-03-11
class Solution {
 public:
  int findLonelyPixel(vector<vector<char>>& picture) {
    if (picture.empty() || picture[0].empty()) return 0;
    int n = picture.size(), m = picture[0].size();
    vector<int> row(n, 0), col(m, 0);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
       row[i] += picture[i][j] == 'B';
       col[j] += picture[i][j] == 'B';
      }
    int result = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        result += picture[i][j] == 'B' && row[i] == 1 && col[j] == 1;
    return result;
  }
};
