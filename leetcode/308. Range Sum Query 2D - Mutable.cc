// Copyright 2017 Qi Wang
// Date: 2017-09-10
// Refer to: https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
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
 
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> matrix) {
    for (const auto& nums : matrix) {
      trees_.emplace_back(nums);
    }
  }
  
  void update(int row, int col, int val) {
    trees_[row].Update(col + 1, val);
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int i = row1; i <= row2; ++i) {
      sum += trees_[i].Sum(col1 + 1, col2 + 1);
    }
    return sum;
  }
 
 private:
  vector<BIT> trees_;
};
