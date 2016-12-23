// Copyright 2016 Qi Wang
// Date: 2016-12-22
class NumArray {
 public:
  NumArray(vector<int> &nums) : CAPACITY(nums.size()) {
    if (CAPACITY == 0) return;
    sums_.resize((CAPACITY + 1) << 2);
    build(1, CAPACITY, ROOT, nums);
  }

  void update(int i, int val) {
    update(i + 1, val, ROOT, 1, CAPACITY);
  }

  int sumRange(int i, int j) {
    return sum(i + 1, j + 1, ROOT, 1, CAPACITY);
  }

 private:
  inline int left(int i) const { return i << 1; }

  inline int right(int i) const { return left(i) + 1; }

  int build(int begin, int end, int idx, const vector<int>& nums) {
    if (begin == end) {
      return sums_[idx] = nums[begin - 1];
    } else {
      int mid = begin + end >> 1;
      return sums_[idx] = build(begin, mid, left(idx), nums)
          + build(mid + 1, end, right(idx), nums);
    }
  }

  int sum(int qL, int qR, int idx, int l, int r) {
    if (qL == l && qR == r)
      return sums_[idx];
    int mid = l + r >> 1;
    if (qR <= mid) {
      return sum(qL, qR, left(idx), l, mid);
    } else if (qL > mid) {
      return sum(qL, qR, right(idx), mid + 1, r);
    } else {
      return sum(qL, mid, left(idx), l, mid)
          + sum(mid + 1, qR, right(idx), mid + 1, r);
    }
  }

  int update(int qIdx, int val, int idx, int l, int r) {
    if (l == r && l == qIdx) return sums_[idx] = val;
    int mid = l + r >> 1;
    return sums_[idx] = qIdx <= mid
        ? update(qIdx, val, left(idx), l, mid) + sums_[right(idx)]
        : sums_[left(idx)] + update(qIdx, val, right(idx), mid + 1, r);
  }

  vector<int> sums_;
  const int CAPACITY;
  static constexpr int ROOT = 1;
};
