// Copyright 2016 Qi Wang
// Date: 2016-10-06
class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> cnts(26, 0);
    for (char c : s) ++cnts[c - 'a'];
    for (size_t i = 0; i < s.size(); ++i)
      if (cnts[s[i] - 'a'] == 1) return i;
    return -1;
  }
};
