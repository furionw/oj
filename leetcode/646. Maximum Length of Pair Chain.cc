// Copyright 2017 Qi Wang
// Date: 2017-07-22
class Solution {
 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(),
        [](const vector<int>& lhs, const vector<int>& rhs) {
          return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
        });
    int sz = pairs.size();
    vector<int> dp(sz, 1);
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < i; ++j) {
        if (pairs[j][1] < pairs[i][0]) {
          dp[i] = max(dp[j] + 1, dp[i]);
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
