// Copyright 2017 Qi Wang
// Date: 2017-07-18
class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    if (abs(int(s.size()) - int(t.size())) > 1) return false;
    int diff_cnt = 0;
    if (s.size() == t.size()) {
      for (size_t i = 0; i < s.size(); ++i) {
        diff_cnt += s[i] != t[i];
      }
      return 1 == diff_cnt;
    } else {
      if (s.size() > t.size()) swap(s, t);
      for (size_t i = 0; i < s.size();) {
        if (s[i] != t[i + diff_cnt]) {
          if (diff_cnt) {
            return false;
          } else {
            ++diff_cnt;
          }
        } else {
          ++i;
        }
      }
      return diff_cnt <= 1;
    }
  }
};
