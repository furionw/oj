// Copyright 2016 Qi Wang
// Date: 2016-12-28
class Solution {
 public:
  vector<string> generatePossibleNextMoves(string s) {
    vector<string> res;
    for (size_t i = 0; i + 1 < s.size(); ++i) {
      if (s[i] == s[i + 1] && s[i] == '+') {
        s[i] = s[i + 1] = '-';
        res.push_back(s);
        s[i] = s[i + 1] = '+';
      }
    }
    return res;
  }
};
