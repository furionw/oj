// Date: 2022-10-08
// The idea of maintaining lcs
// Refer to: https://leetcode.com/problems/maximum-deletions-on-a-string/discuss/2648900/JavaC%2B%2BPython-DP-Solution
class Solution {
 public:
  int deleteString(string s) {
    vector<int> dp(s.size(), 1);
    vector<vector<int>> lcs(s.size() + 1, vector<int>(s.size() + 1, 0));
    for (int i = s.size() - 1; i >= 0; --i) {
      for (int j = i + 1; j < s.size(); ++j) {
        if (s[i] == s[j]) {
          lcs[i][j] = 1 + lcs[i + 1][j + 1];
        }
        if (lcs[i][j]  >= j - i) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    return dp[0];
  }
};
