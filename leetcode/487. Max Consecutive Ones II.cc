// Copyright 2017 Qi Wang
// Date: 2017-01-17
// Refer to: https://discuss.leetcode.com/topic/75721/c-5-lines-o-n-o-1
// It seems that this impl is slower than the former one
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ones = 0, pre_ones = 0, result = 0;
    for (int num : nums) {
      if (num == 0) {
        result = max(result, ones + pre_ones);
        pre_ones = ones;
        ones = 0;
      } else {
        result = max(result, ++ones);
      }
    }
    return max(result, ones + pre_ones) + (ones == nums.size() ? 0 : 1);
  }
};

// Date: 2017-01-17
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int result = 1;
    vector<int> cnts(nums.size(), 0);
    for (int i = 0, cnt = cnts[0]; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        result = max(result, cnts[i] = ++cnt);
        // flip previous 0
        int start = i - cnt - 1;
        int mid = start + 1;
        if (mid >= 0 && nums[mid] == 0)
          result = max(result, (start >= 0 ? cnts[start] : 0) + 1 + cnt);
      } else {
        // flip current 0
        result = max(result, cnt + 1);
        cnt = 0;
      }
    }
    return result;
  }
};
