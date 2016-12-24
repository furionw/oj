// Copyright 2016 Qi Wang
// Date: 2016-12-24
// Refer to the "Top Solutions"
class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    for (size_t i = 1; i < nums.size(); ++i)
      if ((i & 1 && nums[i - 1] > nums[i])
          || (!(i & 1) && nums[i - 1] < nums[i]))
        swap(nums[i - 1], nums[i]);
  }
};
