// Copyright 2017 Qi Wang
// Date: 2017-07-29
// Method 2
// Refer to: 2rd place, twangai's solution
class Solution {
 public:
  int minSteps(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 2 * i; j <= n; j += i) {
        // j / i: 1 copy all op + (j - 1) paste op
        dp[j] = min(dp[j], dp[i] + j / i);
      }
    }
    return dp[n];
  }
};

// Date: 2017-07-29
class Solution {
 public:
  int minSteps(int n) {
    if (n == 1) return 0;
    int result = n;
    minSteps(1, n, 1, 1, &result);
    return result;
  }

 private:
  void minSteps(int acc, int target, int cur_copy, int op_cnt, int* result) {
    if (op_cnt > *result || acc > target) {
      return;
    } else if (acc == target) {
      *result = min(*result, op_cnt);
      return;
    }
    minSteps(acc + cur_copy, target, cur_copy, op_cnt + 1, result);
    if (acc > cur_copy)
      minSteps(acc, target, acc, op_cnt + 1, result);
  }
};
