// Copyright 2017 Qi Wang
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
