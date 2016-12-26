// Copyright 2016 Qi Wang
// Date: 2016-12-26
class Solution {
 public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    if (nums.empty()) return vector<string>(1, makeRange(lower, upper));
    vector<string> res;
    if (lower < nums.front())
      res.push_back(makeRange(lower, nums.front() - 1));
    for (size_t i = 0; i < nums.size() - 1; ++i)
      if (nums[i] != nums[i + 1] && nums[i] + 1 < nums[i + 1])
        res.push_back(makeRange(nums[i] + 1, nums[i + 1] - 1));
    if (nums.back() < upper)
      res.push_back(makeRange(nums.back() + 1, upper));
    return res;
  }

 private:
  string makeRange(int l, int r) const {
    return l == r ? to_string(l) : to_string(l) + "->" + to_string(r);
  }
};
