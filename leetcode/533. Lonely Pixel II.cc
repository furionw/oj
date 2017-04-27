// Copyright 2017 Qi Wang
// Date: 2017-04-26
class Solution {
 public:
  int findBlackPixel(vector<vector<char>>& picture, int N) {
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
        if (picture[i][j] == 'B' && row[i] == N && col[j] == N) {
          bool valid = true;
          for (int k = 0; k < n && valid; ++k)
            if (k != i && picture[k][j] == picture[i][j])
              valid = equal(picture[i].begin(), picture[i].end(),
                  picture[k].begin());
          if (valid) ++result;
        }
    return result;
  }
};
