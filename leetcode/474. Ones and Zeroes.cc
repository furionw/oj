// 2025-06-11
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (const auto& str: strs) {
      int zeros = count(str.begin(), str.end(), '0');
      int ones = str.size() - zeros;
      for (int i = m; i >= 0; --i) {
        for (int j = n; j >= 0; --j) {
          int prevZeros = i - zeros;
          int prevOnes = j - ones;
          if (prevZeros < 0 || prevOnes < 0) {
            continue;
          }
          dp[i][j] = max(dp[i][j], dp[prevZeros][prevOnes] + 1);
        }
      }
    }
    return dp[m][n];
  }
};

// Date: 2016-12-29
class Solution {
 public:
  // m : 0s, n : 1s
  int findMaxForm(vector<string>& strs, int m, int n) {
    // It seems that this init doesn't work
    // The more detail explaination could be seen via:
    // http://stackoverflow.com/questions/41376487/initialize-two-2-d-array-to-zero-in-c-c
    int dp[m + 1][n + 1] = {{0}};
    // Get "Wrong Answer" without memset() function below
    memset(dp, 0, sizeof dp);
    for (auto& str : strs) {
      auto cost = getCost(str);
      for (int i = 0; i + cost.first <= m; ++i)
        for (int j = 0; j + cost.second <= n; ++j)
          dp[i][j] = std::max(dp[i + cost.first][j + cost.second] + 1,
              dp[i][j]);
    }
    int max = 0;
    for (int i = 0; i <= m; ++i)
      for (int j = 0; j <= n; ++j)
        max = std::max(max, dp[i][j]);
    return max;
  }

 private:
  pair<int, int> getCost(const string& str) const {
    int cnts[] = {0, 0};
    for (char c : str) ++cnts[static_cast<char>(c == '1')];
    return {cnts[0], cnts[1]};
  }
};
