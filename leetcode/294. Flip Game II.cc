// Copyright 2016 Qi Wang
// Date: 2016-12-28
class Solution {
 public:
  bool canWin(string s) {
    for (size_t i = 0; i + 1 < s.size(); ++i) {
      if (s[i] == s[i + 1] && s[i] == '+') {
        s[i] = s[i + 1] = '-';
        if (!canWin(s)) return true;
        s[i] = s[i + 1] = '+';
      }
    }
    return false;
  }
};
