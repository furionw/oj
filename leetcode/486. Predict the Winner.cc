// Copyright 2017 Qi Wang
// Date: 2017-06-08
// Method 2: 3ms
// Refer to: https://discuss.leetcode.com/topic/76312/java-1-line-recursion-solution
class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    if (nums.empty()) return true;
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), INT_MAX));
    return helper(nums, 0, nums.size() - 1, dp) >= 0;
  }
 
 private:
  int helper(const vector<int>& nums, int s, int e,
      vector<vector<int>>& dp) const {
    if (dp[s][e] == INT_MAX)
      dp[s][e] = s == e ? nums[s] : max(nums[s] - helper(nums, s + 1, e, dp),
          nums[e] - helper(nums, s, e - 1, dp));
    return dp[s][e];
  }
};

// Date: 2017-06-08
// Method 1: 26ms
class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    list<int> num_list(nums.begin(), nums.end());
    return P1(num_list, 0, 0);
  }
 
 private:
  // return true if P1 can win
  bool P1(list<int>& nums, int sum1, int sum2) const {
    if (nums.empty()) return sum1 >= sum2;
    // front
    int num = nums.front(); nums.pop_front();
    if (P2(nums, sum1 + num, sum2)) {
      nums.push_front(num);
      return true;
    }
    nums.push_front(num);
    // back
    num = nums.back(); nums.pop_back();
    if (P2(nums, sum1 + num, sum2)) {
      nums.push_back(num);
      return true;
    }
    nums.push_back(num);
    return false;
  }
 
  // return true if P1 can win
  bool P2(list<int>& nums, int sum1, int sum2) const {
    if (nums.empty()) return sum1 >= sum2;
    // front
    int num = nums.front(); nums.pop_front();
    if (!P1(nums, sum1, sum2 + num)) {
      nums.push_front(num);
      return false;
    }
    nums.push_front(num);
    // back
    num = nums.back(); nums.pop_back();
    if (!P1(nums, sum1, sum2 + num)) {
      nums.push_back(num);
      return false;
    }
    nums.push_back(num);
    return true;
  }
};
