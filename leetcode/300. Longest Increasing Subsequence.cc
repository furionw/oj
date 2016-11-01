// Copyright 2016 Qi Wang
// Date: 2016-11-01
// method 2
class Solution {
 public:
  inline int lengthOfLIS(vector<int>& nums) {
    // Do not forget this!!!
    if (nums.empty()) return 0;
    vector<int> dp(nums.size(), 1);
    for (size_t i = 1; i < nums.size(); ++i)
      for (size_t j = 0; j < i; ++j)
        dp[i] = nums[i] > nums[j] ? max(dp[i], dp[j] + 1) : dp[i];
    return *max_element(dp.begin(), dp.end());
  }
};

// Date: 2016-11-01
// method 1
// valarray is not supported by LeetCode
class Solution {
 public:
  inline int lengthOfLIS(vector<int>& nums) {
    // Do not forget this!!!
    if (nums.empty()) return 0;
    valarray<int> dp(1, nums.size());
    for (size_t i = 1; i < nums.size(); ++i)
      for (size_t j = 0; j < i; ++j)
        dp[i] = nums[i] > nums[j] ? max(dp[i], dp[j] + 1) : dp[i];
    return dp.max();
  }
};
