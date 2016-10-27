// Copyright 2016 Qi Wang
// Date: 2016-10-27
// shared_ptr is a time consuming operation which might cause TLE here,
// depending on the server performance. It's suggested that implementing the
// segment tree using array.
#include <cstdio>
#include <algorithm>
#include <memory>

class SegmentTree {
 public:
  // nums[begin, ... , end]
  SegmentTree(int nums[], int begin, int end) : begin_(begin), end_(end) {
    if (begin_ == end_) {
      min_ = nums[begin];
    } else {
      int mid = this->mid();
      // method 1: with shared_ptr
      left_ = std::make_shared<SegmentTree>(nums, begin, mid);
      right_ = std::make_shared<SegmentTree>(nums, mid + 1, end);
      // method 2: with *
      // left_ = new SegmentTree(nums, begin, mid);
      // right_ = new SegmentTree(nums, mid + 1, end);
      min_ = std::min(left_->min_, right_->min_);
    }
  }

  // nums[begin, ... , end]
  int min(int begin, int end) const {
    int mid = this->mid();
    if (begin == begin_ && end == end_) {
      return min_;
    } else if (end <= mid) {
      return left_->min(begin, end);
    } else if (begin >= mid + 1) {
      return right_->min(begin, end);
    } else {
      return std::min(left_->min(begin, mid), right_->min(mid + 1, end));
    }
  }

  int modify(int idx, int value) {
    if (left_ == nullptr) {
      min_ = value;
    } else {
      int mid = this->mid();
      if (idx <= mid) {
        left_->modify(idx, value);
      } else {
        right_->modify(idx, value);
      }
      min_ = std::min(left_->min_, right_->min_);
    }
    return min_;
  }

 private:
  inline int mid() const { return (begin_ + end_) >> 1; }

  int begin_, end_, min_;
  // method 1: with shared_ptr
  std::shared_ptr<SegmentTree> left_ = nullptr, right_ = nullptr;
  // method 2
  // SegmentTree *left_ = nullptr, *right_ = nullptr;
};

int main() {
  int n;
  scanf("%d", &n);
  constexpr int MAXN = 1e6 + 5;
  int nums[MAXN];
  for (int i = 1; i <= n; ++i)
    scanf("%d", &nums[i]);
  SegmentTree root(nums, 1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 0) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", root.min(l, r));
    } else {
      int idx, weight;
      scanf("%d%d", &idx, &weight);
      root.modify(idx, weight);
    }
  }
}
