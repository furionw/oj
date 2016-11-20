// Copyright 2016 Qi Wang
// Refer to: https://discuss.leetcode.com/topic/64442/easy-to-understand-js-solution
// Date: 2016-11-19
class Solution {
 public:
  int findKthNumber(int n, int k) {
    int64_t prefix = 0;
    while (k) {
      for (int i = 0; i <= 9; ++i) {
        int cnt = countForPrefix(n, prefix * 10 + i);
        if (cnt < k) {
          k -= cnt;
        } else {
          --k;  // eleminate the number "prefix(0...0)"
          prefix = prefix * 10 + i;
          break;
        }
      }
    }
    return prefix;
  }

 private:
  int countForPrefix(int64_t n, int64_t prefix) {
    if (!prefix) return 0;  // 0 is an invalid prefix
    int64_t a = prefix, b = prefix + 1;
    int cnt = 0;
    for (; a <= n; a *= 10, b *= 10)
      // n + 1 means we need to count in the number "a(0...000)" when n + 1 < b
      cnt += min(n + 1, b) - a;
    return cnt;
  }
};
