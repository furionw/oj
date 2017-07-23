// Copyright 2017 Qi Wang
// Date: 2017-07-22
class Solution {
 public:
  int countSubstrings(string s) {
    int result = 0;
    for (int len = 1; len <= s.size(); ++len) {
      for (int pos = 0; pos + len <= s.size(); ++pos) {
        result += IsP(s.substr(pos, len));
      }
    }
    return result;
  }

 private:
  // non empty str
  bool IsP(const string& str) {
    for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
      if (str[i] != str[j]) {
        return false;
      }
    }
    return true;
  }
};