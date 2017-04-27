// Copyright 2017 Qi Wang
// Date: 2017-04-27
// Refer to: https://discuss.leetcode.com/topic/85040/i-feel-this-problem-is-just-perfect-for-april-fools-day/15
class Solution {
 public:
  int findLUSlength(string a, string b) {
    return a == b ? -1 : max(a.size(), b.size());
  }
};
