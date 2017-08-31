// Copyright 2017 Qi Wang
// Date: 2017-08-30
class Solution {
 public:
  int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int result = 0;
    for (int i = 0; i < nums.size(); i += 2) result += nums[i];
    return result;
  }
};

// Date: 2017-04-24
class Solution {
 public:
  int arrayPairSum(vector<int>& nums) {
    if (nums.empty() || nums.size() & 1) return INT_MIN;
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2)
      sum += nums[i];
    return sum;
  }
};
