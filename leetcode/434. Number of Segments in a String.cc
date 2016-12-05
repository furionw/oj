// Copyright 2016 Qi Wang
// Date: 2016-12-05
class Solution {
 public:
  int countSegments(string s) {
    int res = 0;
    bool findChar = false;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        if (findChar) {
          ++res;
          findChar = false;
        }
      } else {
        findChar = true;
      }
    }
    res += findChar;
    return res;
  }
};
