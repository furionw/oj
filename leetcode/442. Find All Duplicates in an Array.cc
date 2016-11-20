// Copyright 2016 Qi Wang
// Date: 2016-11-20
class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
      while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
        swap(nums[i], nums[nums[i] - 1]);
    vector<int> res;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
      if (nums[i] != i + 1)
        res.push_back(nums[i]);
    return res;
  }
};
