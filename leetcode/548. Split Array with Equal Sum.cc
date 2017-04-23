// Copyright 2017 Qi Wang
// Date: 2017-04-23
// Refer to: https://discuss.leetcode.com/topic/85026/simple-java-solution-o-n-2/6
class Solution {
 public:
  bool splitArray(vector<int>& nums) {
    if (nums.size() < 7) return false;
    for (size_t i = 1; i < nums.size(); ++i)
      nums[i] += nums[i - 1];
    for (size_t j = 3; j < nums.size() - 3; ++j) {
      unordered_set<int> sums;
      for (size_t i = 1; i < j - 1; ++i)
        if (nums[i - 1] == nums[j - 1] - nums[i])
          sums.insert(nums[i - 1]);
      for (size_t k = j + 2; k < nums.size() - 1; ++k)
        if (nums[k - 1] - nums[j] == nums.back() - nums[k]
            && sums.count(nums[k - 1] - nums[j]) == 1)
          return true;
    }
    return false;
  }
};
