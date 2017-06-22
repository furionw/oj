// Copyright 2017 Qi Wang
// Date: 2017-06-22
// Refer to: https://discuss.leetcode.com/topic/90571/java-solution-dp
class Solution {
 public:
  int findIntegers(int num) {
    vector<int> bits;
    for (; num > 0; num >>= 1)
      bits.push_back(num % 2);
    vector<int> a(bits.size()), b(bits.size());
    a[0] = b[0] = 1;
    for (size_t i = 1; i < bits.size(); ++i) {
      a[i] = a[i - 1] + b[i - 1];
      b[i] = a[i - 1];
    }
    int result = a.back() + b.back();
    for (int i = int(bits.size()) - 2; i >= 0; --i) {
      if (bits[i] + bits[i + 1] == 2) break;
      if (bits[i] + bits[i + 1] == 0) result -= b[i];
    }
    return result;
  }
};
