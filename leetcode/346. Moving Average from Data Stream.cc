// 2025-07-16
class MovingAverage {
 public:
  MovingAverage(int size): size_(size) {}
    
  double next(int val) {
    vals_.push_back(val);
    sum_ += val;
    if (vals_.size() > size_) {
      sum_ -= vals_.front();
      vals_.pop_front();
    }
    return sum_ / vals_.size();
  }

 private:
  list<double> vals_;
  double sum_ = 0;
  int size_;
};

// Date: 2016-12-23
// Revisit on 2017-09-12
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
