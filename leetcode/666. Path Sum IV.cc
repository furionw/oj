// Copyright 2017 Qi Wang
// Date: 2017-08-26
class Solution {
 public:
  int pathSum(vector<int>& nums) {
    nums_ = vector<int>(16, INT_MAX);
    for (int num : nums) {
      int d = num / 100;
      int p = num / 10 % 10;
      int v = num % 10;
      nums_[get_idx(d, p)] = v;
    }
    auto result = acc(1);
    return accumulate(result.begin(), result.end(), 0);
  }

 private:
  vector<int> acc(int idx) const {
    if (idx >= nums_.size()) return {};
    vector<int> result;
    if (nums_[left(idx)] != INT_MAX)
      for (int sum : acc(left(idx)))
        result.push_back(nums_[idx] + sum);
    if (nums_[right(idx)] != INT_MAX)
      for (int sum : acc(right(idx)))
        result.push_back(nums_[idx] + sum);
    if (result.empty())
      result.push_back(nums_[idx]);
    return result;
  }

  int get_idx(int d, int p) const {
    return pow(2, d - 1) - 1 + p;
  }
  int left(int idx) const { return idx << 1; }
  int right(int idx) const { return left(idx) + 1; }

  vector<int> nums_;
};