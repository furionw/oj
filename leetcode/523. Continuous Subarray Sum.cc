// Copyright 2017 Qi Wang
// Date: 2017-11-08
// Case 1: [0], 0 -> false
// Case 2: [0, 0], 0 -> true
// Case 3: [1, 2, 3, 4], 5 -> true
class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    if (k == 0) {
      for (int i = 0; i + 1 < nums.size(); ++i) {
        if (nums[i] == 0 && nums[i + 1] == 0) return true;
      }
      return false;
    }
    unordered_map<int, int> remainder_to_idx_map;
    remainder_to_idx_map[0] = -1;
    for (int i = 0, remainder = 0; i < nums.size(); ++i) {
      remainder = (remainder + nums[i]) % k;
      if (remainder_to_idx_map.count(remainder)) {
        if (i - remainder_to_idx_map[remainder] > 1) {
          return true;
        }
      } else {
        remainder_to_idx_map[remainder] = i;
      }
    }
    return false;
  }
};

// Date: 2017-08-06
class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    for (int i = 0; i + 1 < nums.size(); ++i) {
      if (nums[i] == 0 && nums[i + 1] == 0) {
        return true;
      }
    }
    if (k == 0) return false;
    // You don't necessary need this
    // k = abs(k);
    unordered_map<int, int> acc_to_idx_map;
    acc_to_idx_map[0] = -1;
    int acc = 0;
    for (int i = 0; i < nums.size(); ++i) {
      acc = (acc + nums[i]) % k;
      if (acc_to_idx_map.find(acc) != acc_to_idx_map.end()) {
        if (i - acc_to_idx_map[acc] >= 2) return true;
      } else {
        acc_to_idx_map[acc] = i;
      }
    }
    return false;
  }
};

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
