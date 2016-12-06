// Copyright 2016 Qi Wang
// Method 2: heap
// ...

// Method 1: std::upper_bound
// Date: 2016-12-06
class MedianFinder {
 public:
  // Adds a number into the data structure.
  void addNum(int num) {
    nums_.insert(upper_bound(nums_.begin(), nums_.end(), num), num);
  }

  // Returns the median of current data stream
  double findMedian() {
    int n = nums_.size();
    // odd
    if (n & 1) {
      return nums_[n >> 1];
    } else {
      return (nums_[n >> 1] + nums_[(n >> 1) - 1]) / 2.;
    }
  }

 private:
  vector<int> nums_;
};
