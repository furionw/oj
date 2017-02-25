// Copyright 2017 Qi Wang
// Date: 2017-02-25
class Solution {
 public:
  int countArrangement(int N) {
    bitset<16> bits;
    return count_arrangement(1, N, bits);
  }

 private:
  int count_arrangement(int cur_idx, int n, bitset<16>& bits) const {
    if (cur_idx > n) return 1;
    int result = 0;
    for (int i = 1; i <= n; ++i) {
      if (bits.test[i] && (n % i == 0 || i % n == 0)) {
        bits.set(i);
        result += count_arrangement(cur_idx + 1, n, bits);
        bits.reset(i);
      }
    }
    return result;
  }
};
