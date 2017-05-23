// Copyright 2017 Qi Wang
// Date: 2017-05-23
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> mins(nums.size());
    int minimal = nums.back();
    for (int i = nums.size() - 1; i >= 0; --i)
      mins[i] = minimal = min(minimal, nums[i]);
    vector<int> maxs(nums.size());
    int maximal = nums.front();
    for (int i = 0; i < nums.size(); ++i)
      maxs[i] = maximal = max(maximal, nums[i]);
    int begin = 0;
    for (; begin < nums.size() && nums[begin] <= mins[begin]; ++begin) {}
    int end = nums.size() - 1;
    for (; begin <= end && nums[end] >= maxs[end]; --end) {}
    return begin <= end ? (end - begin + 1) : 0;
  }
};
