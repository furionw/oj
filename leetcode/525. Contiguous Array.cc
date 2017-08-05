// Copyright 2017 Qi Wang
// Date: 2017-08-04
class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    // Count "1" as 1, "0" as -1
    unordered_map<int, int> acc_to_idx_map;
    acc_to_idx_map[0] = -1;
    int result = 0;
    for (int i = 0, acc = 0; i < nums.size(); ++i) {
      acc += nums[i] == 1 ? 1 : -1;
      if (acc_to_idx_map.find(acc) != acc_to_idx_map.end()) {
        result = max(result, i - acc_to_idx_map[acc]);
      } else {
        acc_to_idx_map[acc] = i;
      }
    }
    return result;
  }
};

// Date: 2017-02-25
// Refer to: https://discuss.leetcode.com/topic/79906/easy-java-o-n-solution-presum-hashmap
class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> m;
    m[0] = -1;
    for (int& num : nums)
      if (num == 0) num = -1;
    int result = 0, sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (m.count(sum)) {
        result = max(result, i - m[sum]);
      } else {
        m[sum] = i;
      }
    }
    return result;
  }
};
