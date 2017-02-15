// Copyright 2017 Qi Wang
// Date: 2017-02-09
// Refer to: https://discuss.leetcode.com/topic/74627/3-line-c
class Solution {
 public:
  int findComplement(int num) {
    unsigned mask = ~0;
    while (mask & num) mask <<= 1;
    return ~mask & ~num;  // or ~mask ^ num
  }
};

// Date: 2017-02-09
class Solution {
 public:
  // num : positive integer
  int findComplement(int num) {
    bool find_one = false;
    for (int i = 30; i >= 0; --i) {
      int mask = 1 << i;
      find_one = find_one || (num & mask);
      if (find_one) {
        if (num & mask) {
          num -= mask;
        } else {
          num |= mask;
        }
      }
    }
    return num;
  }
};
