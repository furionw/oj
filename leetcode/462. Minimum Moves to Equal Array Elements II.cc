// Copyright 2016 Qi Wang
// Date: 2016-11-23
// The proof could be seen here: http://blog.csdn.net/liuchenjane/article/details/53244689
class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    // "You may assume the array's length is at most 10,000."
    int median = nums[nums.size() >> 1];
    return accumulate(nums.begin(), nums.end(), 0, [median](int res, int cur) {
      return res + abs(cur - median);
    });
  }
};
