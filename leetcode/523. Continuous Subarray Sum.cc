// Copyright 2017 Qi Wang
// Refer to: https://discuss.leetcode.com/topic/80793/java-o-n-time-o-k-space/40
// Date: 2017-03-04
class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    // sum -> idx
    unordered_map<int, int> sums;
    sums[0] = -1;
    int acc = 0;
    for (int i = 0; i < nums.size(); ++i) {
      acc += nums[i];
      if (k != 0) acc %= k;
      // found
      if (sums.count(acc) > 0) {
        if (i - sums[acc] >= 2) return true;
      // not found
      } else {
        sums[acc] = i;
      }
    }
    return false;
  }
};

// Date: 2017-03-04
class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    auto sum = nums;
    for (size_t len = 2; len <= nums.size(); ++len) {
      for (size_t i = len - 1; i < nums.size(); ++i) {
        sum[i] += nums[i - len + 1];
        if (sum[i] == k || (k != 0 && sum[i] % k == 0)) return true;
      }
    }
    return false;
  }
};
