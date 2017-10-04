// Copyright 2017 Qi Wang
// Date: 2017-10-03
// Case 1: " abc def"
//   i = 0, pos = 3
//   i = 4, pos = string::npos
//   i = 7
class Solution {
 public:
  string reverseWords(string &s) {
    string result;
    for (int i = 0; i < s.size();) {
      for (; i < s.size() && s[i] == ' '; ++i) {}
      if (i < s.size()) {
        if (!result.empty()) result = string(" ") + result;
        int pos = s.find(' ', i);
        if (pos == string::npos) {
          result = s.substr(i) + result;
          i = s.size();
        } else {
          result = s.substr(i, pos - i) + result;
          i = pos + 1;
        }
      }
    }
    return result;
  }
};
