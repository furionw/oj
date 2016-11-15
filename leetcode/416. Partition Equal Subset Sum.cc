// Copyright 2016 Qi Wang
// Method 2
// Dynamic programming
// Refer to: https://discuss.leetcode.com/topic/62271/c-solution-with-dynamic-programming/4
// Date: 2016-11-15
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    int target = sum >> 1;
    // dp[i][j] is true iff the sum of the subset of the first j numbers is i
    bool dp[1 + target][nums.size() + 1];
    for (int i = 0; i <= target; ++i)
      for (int j = 0; j <= nums.size(); ++j)
        dp[i][j] = !i;
    for (int i = 1; i <= target; ++i)
      for (int j = 1; j <= nums.size(); ++j)
        if (nums[j - 1] <= i)
          dp[i][j] = dp[i][j - 1] || dp[i - nums[j - 1]][j - 1];
    return dp[target][nums.size()];
  }
};

// Method 1
// TLE: nums.size() <= 200, 2^200 is too large!!!
// Date: 2016-11-14
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    return canPartition(nums, 0, 0, 0);
  }
 
 private:
  bool canPartition(vector<int>& nums, size_t cur, int sum1, int sum2) {
    return cur == nums.size()
        ? sum1 == sum2
        : canPartition(nums, cur + 1, sum1 + nums[cur], sum2)
            || canPartition(nums, cur + 1, sum1, sum2 + nums[cur]);
  }
};
