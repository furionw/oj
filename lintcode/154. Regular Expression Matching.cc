// Copyright 2017 Qi Wang
// Date: 2017-10-11
// Case 1: "a", ""
// Case 2: "ab", ".."
// Case 3: "aab", "a*b*"
// Case 3: "aab", "a*ab*"
class Solution {
 public:
  bool isMatch(string s, string p) {
    return IsMatch(s, 0, p, 0);
  }
 
 private:
  bool IsMatch(const string& s, int i, const string& p, int j) const {
    if (i == s.size()) {
      if ((p.size() - j) % 2 == 1) return false;
      for (bool flag = false; j < p.size(); ++j, flag = !flag)
        if (flag && p[j] != '*') return false;
    }
    if (j == p.size()) {
      return i == s.size() && j == p.size();
    }
    if (j + 1 < p.size() && p[j + 1] == '*') {
      return (IsMatch(s[i], p[j]) && IsMatch(s, i + 1, p, j)) ||
             IsMatch(s, i, p, j + 2);
    } else {
      return IsMatch(s[i], p[j]) && IsMatch(s, i + 1, p, j + 1);
    }
  } 
 
  bool IsMatch(char s, char p) const {
    return p == '.' || s == p;
  }
};
