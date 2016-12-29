// Copyright 2016 Qi Wang
// Date: 2016-12-29
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    string res;
    int cnts[26];
    memset(cnts, 0, sizeof cnts);
    for (char c : s) ++cnts[c - 'a'];
    for (char c : s) {
      --cnts[c - 'a'];
      size_t pos = res.find(c);
      if (pos == string::npos) {
        while (!res.empty() && res.back() > c && cnts[res.back() - 'a'] > 0)
          res.pop_back();
        res += c;
      } else if (pos != res.size() - 1 && c > res[pos + 1]) {
        res = res.substr(0, pos) + res.substr(pos + 1);
        while (!res.empty() && res.back() > c && cnts[res.back() - 'a'] > 0)
          res.pop_back();
        res += c;
      }
    }
    return res;
  }
};
