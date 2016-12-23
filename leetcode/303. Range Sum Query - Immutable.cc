// Copyright 2016 Qi Wang
// Date: 2016-12-22
class NumArray {
 public:
  NumArray(vector<int> &nums) : sums_(move(nums)) {
    for (size_t i = 1; i < sums_.size(); ++i)
      sums_[i] += sums_[i - 1];
  }

  int sumRange(int i, int j) {
    return i == 0 ? sums_[j] : sums_[j] - sums_[i - 1];
  }

 private:
  vector<int> sums_;
};
