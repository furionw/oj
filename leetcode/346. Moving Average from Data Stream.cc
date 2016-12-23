// Copyright 2016 Qi Wang
// Date: 2016-12-23
class MovingAverage {
 public:
  /** Initialize your data structure here. */
  MovingAverage(int size) : CAPACITY_(size) {}

  double next(int val) {
    if (CAPACITY_ == 0) return 0;
    if (nums_.size() == CAPACITY_) {
      sum_ -= nums_.front();
      nums_.pop_front();
    }
    sum_ += val;
    nums_.push_back(val);
    return sum_ / nums_.size();
  }

 private:
  list<int> nums_;
  double sum_ = 0;  // in case int might not be able to contain the large sum
  const int CAPACITY_;
};
