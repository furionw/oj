// Copyright 2016 Qi Wang
// Date: 2016-11-08
class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int min = INT_MAX;
    for (int num : nums)
      min = std::min(min, num);
    // We do not use accumulate(...) - min * nums.size() here to avoid overflow
    int res = 0;
    for (int num : nums)
      res += num - min;
    return res;
  }
};
