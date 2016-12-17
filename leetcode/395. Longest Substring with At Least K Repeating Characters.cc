// Copyright 2016 Qi Wang
// Date: 2016-12-17
class Solution {
 public:
  int longestSubstring(string s, int k) {
    int cnts[s.size() + 1][26];
    memset(cnts, 0, sizeof cnts);
    int res = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
      copy(cnts[i], cnts[i] + 26, cnts[i + 1]);
      // contain lowercase letters only
      ++cnts[i + 1][s[i] - 'a'];
      for (int j = 0; j + k <= i + 1 && (i + 1) - j > res; ++j) {
        bool valid = true;
        // DO NOT use k to iterate from 0 to 25, 'cause k is the parameter!!!
        for (int p = 0; p < 26 && valid; ++p) {
          int diff = cnts[i + 1][p] - cnts[j][p];
          valid = diff == 0 || diff >= k;
        }
        if (valid) res = (i + 1) - j;
      }
    }
    return res;
  }
};
