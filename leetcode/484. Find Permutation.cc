// Copyright 2017 Qi Wang
// Date: 2017-09-01
// Refer to: https://discuss.leetcode.com/topic/76221/java-o-n-clean-solution-easy-to-understand
class Solution {
 public:
  vector<int> findPermutation(string s) {
    int n = s.size();
    vector<int> result(n + 1);
    for (int i = 0; i <= n; ++i) result[i] = i + 1;
    int d_cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'D') {
        ++d_cnt;
      } else if (d_cnt != 0) {
        reverse(result.begin() + i - d_cnt, result.begin() + i + 1);
        d_cnt = 0;
      }
    }
    if (d_cnt != 0)
      reverse(result.begin() + n - d_cnt, result.end());
    return result;
  }
};
