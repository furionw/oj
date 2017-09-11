// Copyright 2017 Qi Wang
// Date: 2017-09-09
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int longest = 1;
    vector<pair<int, int>> dp(nums.size(), {1, 1});
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (dp[j].first + 1 > dp[i].first) {
            dp[i].first = dp[j].first + 1;
            dp[i].second = dp[j].second;
          } else if (dp[j].first + 1 == dp[i].first) {
            dp[i].second += dp[j].second;
          }
        }
      }
      longest = max(longest, dp[i].first);
    }
    int result = 0;
    for (const auto& p : dp) {
      if (p.first == longest) result += p.second;
    }
    return result;
  }
};