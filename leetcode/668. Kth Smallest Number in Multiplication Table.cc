// Copyright 2017 Qi Wang
// Date: 2017-09-08
// Refer to: https://discuss.leetcode.com/topic/101132/java-solution-binary-search
class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    if (k > m * n) return -1;
    int l = 1, r = m * n + 1;
    while (l < r) {
      int mid = l + r >> 1;
      int cnt = Count(mid, m, n);
      if (cnt < k) {
        l = mid + 1;
        // When k == cnt, it's necessary to let r = mid rather than return
        // directly. Let's because the current 'mid' might not be the k-th
        // smallest number. Tt could be a prime number and the real k-th
        // smallest one is less than this prime number.
      } else {
        r = mid;
      }
    }
    return l;
  }
 
 private:
  int Count(int mid, int m, int n) const {
    int result = 0;
    for (int i = 1; i <= m; ++i) {
      result += min(mid / i, n);
    }
    return result;
  }
};
