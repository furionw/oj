// Copyright 2016 Qi Wang
// Refer to: http://www.cnblogs.com/grandyang/p/5165821.html
// Date: 2016-11-13
class Solution {
 public:
  // nums is sorted already
  int minPatches(vector<int>& nums, int n) {
    int res = 0;
    for (size_t i = 0, miss = 1; miss <= n; ) {
      if (i < nums.size() && nums[i] <= miss) {
          miss += nums[i++];
      } else {
        miss <<= 1;
        ++res;
      }
    }
    return res;
  }
};
