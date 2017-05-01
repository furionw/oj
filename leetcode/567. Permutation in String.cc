// Copyright 2017 Qi Wang
// Date: 2017-05-01
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    char cnts[26];
    memset(cnts, 0, sizeof cnts);
    for (char c : s1) ++cnts[c - 'a'];
    char cur_cnts[26];
    memset(cur_cnts, 0, sizeof cur_cnts);
    for (size_t i = 0; i < s1.size(); ++i) ++cur_cnts[s2[i] - 'a'];
    if (equal(cnts, cnts + 26, cur_cnts)) return true;
    for (size_t i = s1.size(); i < s2.size(); ++i) {
      --cur_cnts[s2[i - s1.size()] - 'a'];
      ++cur_cnts[s2[i] - 'a'];
      if (equal(cnts, cnts + 26, cur_cnts)) return true;
    }
    return false;
  }
};
