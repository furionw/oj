// Copyright 2016 Qi Wang
// Refer to the top solution from LeetCode forum
// Date: 2016-12-17
class Solution {
 public:
  int findSubstringInWraproundString(string p) {
    for (char& c : p) c -= 'a';
    if (p.empty()) return 0;
    int cnts[26];
    memset(cnts, 0, sizeof cnts);
    char c = p[0];
    int cnt = cnts[c] = 1;
    for (size_t i = 1; i < p.size(); ++i) {
      if ((c + cnt) % 26 != p[i]) {
        c = p[i];
        cnts[p[i]] = max(cnts[p[i]], cnt = 1);
      } else {
        cnts[p[i]] = max(cnts[p[i]], ++cnt);
      }
    }
    return accumulate(cnts, cnts + 26, 0);    
  }
};
