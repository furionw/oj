// Copyright 2017 Qi Wang
// Date: 2017-04-16
class Solution {
 public:
  bool checkRecord(string s) {
    int absent_cnt = 0, late_cnt = 0;
    for (char c : s) {
      // absent
      if (c == 'A') {
        if (++absent_cnt > 1) return false;
        late_cnt = 0;  // reset late_cnt
      // late
      } else if (c == 'L') {
        // return false when late_cnt count up to 3
        if (++late_cnt >= 3) return false;
      // present, reset late_cnt
      } else {
        late_cnt = 0;
      }
    }
    return true;
  }
};
