// Copyright 2017 Qi Wang
// Method 2
// Date: 2017-04-30
// Refer to: https://discuss.leetcode.com/topic/87865/java-dp-solution
// The speed is similar to the 1st solution
class Solution {
 public:
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    int N = days.size(), K = days[0].size();
    vector<int> dp(N, INT_MIN);
    dp[0] = 0;
    for (int k = 0; k < K; ++k) {
      vector<int> temp(N, INT_MIN);
      for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
          if (i == j || 1 == flights[i][j])
            temp[j] = max(temp[j], dp[i] + days[j][k]);
      dp = temp;
    }
    return *max_element(dp.begin(), dp.end());
  }
};

// Method 1
// Date: 2017-04-30
class Solution {
 public:
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    vector<vector<int>> memo(days.size(), vector<int>(days[0].size(), 0));
    return dfs(flights, days, 0, 0, memo);
  }

 private:
  int dfs(const vector<vector<int>>& flights, const vector<vector<int>>& days,
      int city, int week, vector<vector<int>>& memo) const {
    if (week == days[0].size()) return 0;
    if (0 != memo[city][week]) return memo[city][week];
    int result = 0;
    for (int candidate = 0; candidate < flights[0].size(); ++candidate)
      if (1 == flights[city][candidate] || city == candidate)
        result = max(result, days[candidate][week] +
            dfs(flights, days, candidate, week + 1, memo));
    return memo[city][week] = result;
  }
};
