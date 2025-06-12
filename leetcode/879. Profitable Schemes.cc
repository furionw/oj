// 2025-06-11
class Solution {
 public:
  int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    vector<vector<vector<int>>> dp(2,
        vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
    int flag = 0;

    // remaining "i" members to spare, while making "j" profit at minimal
    for (int i = 0; i <= n; ++i) {
      dp[1 - flag][i][0] = 1;
    }
    for (int k = 0; k < group.size(); ++k) {
      const auto& prevDp = dp[1 - flag];
      auto& nextDp = dp[flag];
      for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= minProfit; ++j) {
          nextDp[i][j] = prevDp[i][j];
          int ii = i - group[k];
          if (ii < 0) {
            continue;
          }
          int jj = max(0, j - profit[k]);
          nextDp[i][j] = (nextDp[i][j] + prevDp[ii][jj]) % kMod;
        }
      }
      flag = 1 - flag;
    }

    flag = 1 - flag;
    return dp[flag][n][minProfit];
  }

 private:
  static constexpr int kMod = 1e9 + 7;
};

// 2025-06-11
class Solution {
 public:
  int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    int m = accumulate(profit.begin(), profit.end(), 0);
    vector<vector<vector<int>>> dp(2,
        vector<vector<int>>(n + 1, vector<int>(m + 1)));
    int flag = 0;
    dp[1 - flag][0][0] = 1;
    for (int k = 0; k < group.size(); ++k) {
      const auto& prevDp = dp[1 - flag];
      auto& currentDp = dp[flag];
      for (int i = n; i >= 0; --i) {
        int prevI = i - group[k];
        for (int j = m; j >= 0; --j) {
          currentDp[i][j] = prevDp[i][j];
          int prevJ = j - profit[k];
          if (prevI < 0 || prevJ < 0) {
            continue;
          }
          currentDp[i][j] = (prevDp[i][j] + prevDp[prevI][prevJ]) % kMod;
        }
      }
      // inspect(dp[flag]);
      flag = 1 - flag;
    }

    flag = 1 - flag;
    int result = 0;
    for (int i = 0; i <= n; ++i) {
      for (int p = minProfit; p <= m; ++p) {
        result = (result + dp[flag][i][p]) % kMod;
      }
    }

    return result;
  }

 private:
  void inspect(const vector<vector<int>>& dp) const {
    for (const auto& row : dp) {
      for (const auto& elem : row) {
        cout << elem << ", ";
      }
      cout << endl;
    }
    cout << endl;
  }

  static constexpr int kMod = 1e9 + 7;
};
