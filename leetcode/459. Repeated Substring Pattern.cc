// Copyright 2016 Qi Wang
// Date: 2016-11-13
class Solution {
 public:
  bool repeatedSubstringPattern(string str) {
    if (str.size() <= 1) return false;
    for (size_t len = 1; len <= str.size() / 2; ++len)
      if (pred(str, str.substr(0, len)))
        return true;
    return false;
  }
 
 private:
  bool pred(const string& str, const string& p) {
    for (size_t i = p.size(); i < str.size(); i += p.size())
      if (str.substr(i, p.size()) != p)
        return false;
    return true;
  }
};
