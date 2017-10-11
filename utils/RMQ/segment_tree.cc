// Copyright 2016 Qi Wang
// From: hihoCoder 1077
// Date: 2016-10-27
#include <cstdio>
#include <algorithm>
#include <memory>

template <class T, int maxCapacity>
class SegmentTree {
 public:
  SegmentTree(int segmentSz) : segmentSz_(segmentSz) {
    build(1, segmentSz, 1);
  }

  inline T min(int qBegin, int qEnd) const {
    return min(qBegin, qEnd, 1, segmentSz_, ROOT);
  }

  void modify(int qIdx, const T& value) {
    modify(qIdx, value, 1, segmentSz_, ROOT);
  }

 private:
  inline void updateValue(int u) {
    values_[u] = std::min(values_[left(u)], values_[right(u)]);
  }

  void modify(int qIdx, const T& value, int begin, int end, int u) {
    if (begin == end) {
      values_[u] = value;
    } else {
      int mid = (begin + end) >> 1;
      qIdx <= mid
          ? modify(qIdx, value, begin, mid, left(u))
          : modify(qIdx, value, mid + 1, end, right(u));
      updateValue(u);
    }
  }

  T min(int qBegin, int qEnd, int begin, int end, int u) const {
    int mid = (begin + end) >> 1;
    if (qBegin == begin && qEnd == end) {
      return values_[u];
    } else if (qEnd <= mid) {
      return min(qBegin, qEnd, begin, mid, left(u));
    } else if (qBegin >= mid + 1) {
      return min(qBegin, qEnd, mid + 1, end, right(u));
    } else {
      return std::min(min(qBegin, mid, begin, mid, left(u)),
          min(mid + 1, qEnd, mid + 1, end, right(u)));
    }
  }

  void build(int begin, int end, int u) {
    if (begin == end) {
      int segment;
      scanf("%d", &segment);
      values_[u] = segment;
    } else {
      int mid = (begin + end) >> 1;
      build(begin, mid, left(u));
      build(mid + 1, end, right(u));
      updateValue(u);
    }
  }

  inline int left(int i) const { return i << 1; }

  inline int right(int i) const { return left(i) + 1; }

  T values_[maxCapacity << 2]; 
  int segmentSz_;
  static constexpr int ROOT = 1;
};

int main() {
  int n;
  scanf("%d", &n);
  constexpr int MAXN = 1e6 + 5;
  std::unique_ptr<SegmentTree<int, MAXN>> root(new SegmentTree<int, MAXN>(n));
  int q;
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 0) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", root->min(l, r));
    } else {
      int idx, weight;
      scanf("%d%d", &idx, &weight);
      root->modify(idx, weight);
    }
  }
}
