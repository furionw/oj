// Copyright 2017 Qi Wang
// Date: 2017-04-17
// Refer to: http://hihocoder.com/contest/offers13/solution/1070512
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> matrix[i][j];
  auto sumTbl = matrix;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      sumTbl[i][j] = sumTbl[i - 1][j] + matrix[i][j];
  int result = -1;
  for (int up = 1; up <= n; ++up) {
    for (int bot = 1; bot <= n; ++bot) {
      int sum = 0, left = 1;
      for (int right = 1; right <= m; ++right) {
        sum += sumTbl[bot][right] - sumTbl[up - 1][right];
        while (left < right && sum > k) {
          sum -= (sumTbl[bot][left] - sumTbl[up - 1][left]);
          ++left;
        }
        if (sum <= k)
          result = max(result, (bot - up + 1) * (right - left + 1));
      }
    }
  }
  cout << result << endl;
}

// Date: 2017-04-17
// Method 1: TLE
// Similar to LC 363. Max Sum of Rectangle No Larger Than K
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

inline int maxSumSubmatrix(const vector<vector<int>>& matrix, int k) {
  size_t rows = matrix.size(), cols = matrix[0].size();
  int cnt = 0;
  for (int l = 0; l < cols; ++l) {
    vector<int> sums(rows, 0);
    for (int r = l; r < cols; ++r) {
      // update sums
      for (int i = 0; i < rows; ++i) sums[i] += matrix[i][r];
      map<int, int> s;
      s[0] = -1;
      int sum = 0;
      for (int i = 0; i < rows; ++i) {
        sum += sums[i];
        auto it = s.lower_bound(sum - k);
        if (it != s.end())
          cnt = max(cnt, (r - l + 1) * (i - it->second));
        if (s.find(sum) == s.end()) s[sum] = i;
      }
    }
  }
  return cnt;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> matrix[i][j];
  cout << maxSumSubmatrix(matrix, k) << endl;
}
