// Copyright 2017 Qi Wang
// Date: 2017-03-14
class Solution {
 public:
  string reverseStr(string s, int k) {
    for (size_t i = 0; i < s.size(); i += (k << 1))
      reverse(s.begin() + i, i + k < s.size() ? s.begin() + i + k : s.end());
    return s;
  }
};
