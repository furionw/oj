// Copyright 2016 Qi Wang
// Date: 2016-11-06
class Solution {
 public:
  // s: short str
  // t: long str
  bool isSubsequence(string s, string t) {
    size_t sIdx = 0;
    for (size_t i = 0; i < t.size() && sIdx < s.size(); ++i)
      if (t[i] == s[sIdx]) ++sIdx;
    return sIdx == s.size();
  }
};
