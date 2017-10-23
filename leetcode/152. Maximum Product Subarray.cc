// Copyright 2017 Qi Wang
// Date: 2017-10-22
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<vector<int>> dp(nums.size(), vector<int>(2));
    int max_product = dp[0][0] = dp[0][1] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      dp[i][0] = min(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]);
      dp[i][0] = min(dp[i][0], nums[i]);
      dp[i][1] = max(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]);
      dp[i][1] = max(dp[i][1], nums[i]);
      max_product = max(max_product, dp[i][1]);
    }
    return max_product;
  }
};

// Supported by GCC compiler
class Solution {
 public:
  int maxProduct(int A[], int n) {
    int dp[2][n];
    dp[0][0] = A[0];
    dp[1][0] = A[0];

    for (int i = 1; i < n; ++ i)
    {
      dp[0][i] = max(dp[0][i-1]*A[i], dp[1][i-1]*A[i]);
      dp[0][i] = max(dp[0][i], A[i]);
      dp[1][i] = min(dp[0][i-1]*A[i], dp[1][i-1]*A[i]);
      dp[1][i] = min(dp[1][i], A[i]);
    }

    return *max_element(dp[0], dp[0]+n);
  }
};