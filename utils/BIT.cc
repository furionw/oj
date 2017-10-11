// Copyright 2017 Qi Wang
// Date: 2017-09-10
// Refer to: https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
// LC 308. Range Sum Query 2D - Mutable
class BIT {
 public:
  BIT(const vector<int>& nums) {
    nums_.resize(nums.size() + 1);
    copy(nums.begin(), nums.end(), nums_.begin() + 1);
    tree_ = nums_;
    tree_[0] = 0;
    for (int i = 1; i < nums_.size(); ++i) {
      tree_[i] += tree_[i - 1];
    }
    for (int i = 1; i < tree_.size(); ++i) {
      for (int idx = i - (i & -i); idx != 0; idx -= (idx & -idx)) {
        tree_[i] -= tree_[idx];
      }
    }
  }
 
  int Sum(int l, int r) const {
    return Sum(r) - Sum(l - 1);
  }
 
  void Update(int idx, int val) {
    int delta = val - nums_[idx];
    nums_[idx] += delta;
    for (; idx < tree_.size(); idx += (idx & -idx)) {
      tree_[idx] += delta;
    }
  }
 
 private:
  int Sum(int idx) const {
    int sum = 0;
    while (idx > 0) {
      sum += tree_[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
 
  vector<int> tree_;
  vector<int> nums_;
};
 