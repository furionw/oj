// 2025-06-20
// DP
class Solution {
 public:
  int longestCommonSubsequence(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        if (s1[i] == s2[j]) {
          dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]);
        }
      }
    }
    return dp[0][0];
  }
};


// TLE
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    return longestCommonSubsequence(text1, 0, text2, 0);
  }

 private:
  int longestCommonSubsequence(
      const string& s1,
      int idx1,
      const string& s2,
      int idx2) {
    if (idx1 == s1.size() || idx2 == s2.size()) {
      return 0;
    }
    // discard
    int result = longestCommonSubsequence(s1, idx1 + 1, s2, idx2);
    // try to take s1[idx1]
    idx2 = s2.find(s1[idx1], idx2);
    if (idx2 != string::npos) {
      result = max(result,
          1+ longestCommonSubsequence(s1, idx1 + 1, s2, idx2 + 1));
    }
    return result;
  }
};
