// Copyright 2017 Qi Wang
// Date: 2017-08-05
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int result = 0;
    for (; x != 0 || y != 0; x >>= 1, y >>= 1) {
      result += (x & 1) ^ (y & 1);
    }
    return result;
  }
};
  
// Date: 2017-02-18
// Refer to: https://discuss.leetcode.com/topic/72236/my-c-solution-using-bit-manipulation/3
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int cnt = 0;
    for (x ^= y; x != 0; x &= x - 1)
      ++cnt;
    return cnt;
  }
};

// Date: 2017-02-18
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int cnt = 0;
    for (x ^= y; x != 0; x >>= 1)
      cnt += (x & 1);
    return cnt;
  }
};
