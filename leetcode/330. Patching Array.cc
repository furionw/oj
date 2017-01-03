// Copyright 2016 Qi Wang
// Refer to: http://www.cnblogs.com/grandyang/p/5165821.html
// Date: 2016-11-13
class Solution {
 public:
  // nums is sorted already
  int minPatches(vector<int>& nums, int n) {
    int res = 0;
    // loop invariant: [1, miss - 1] always can be formed using 
    // res[0, i - 1] and #res numbers
    // Commented on 2017-01-03
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
