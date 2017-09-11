// Copyright 2017 Qi Wang
// Date: 2017-09-09
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int result = !nums.empty();
    int cur = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        result = max(result, ++cur);
      } else {
        cur = 1;
      }
    }
    return result;
  }
};
