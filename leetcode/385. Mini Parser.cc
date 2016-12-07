// Copyright 2016 Qi Wang
// Date: 2016-12-07
class Solution {
 public:
  NestedInteger deserialize(string s) {
    NestedInteger res;
    if (s.empty()) {
      // do nothing
    } else if (s[0] == '[') {
      for (size_t i = 1; i < s.size() - 1; ++i) {
        size_t begin = i;
        if (s[i++] == '[') {
          for (int cnt = 1; cnt; ++i) {
            if (s[i] == '[') {
              ++cnt;
            } else if (s[i] == ']') {
              --cnt;
            }
          }
          res.add(deserialize(s.substr(begin, i - begin)));
        } else {
          for (; '0' <= s[i] && s[i] <= '9'; ++i) {}
          res.add(stoi(s.substr(begin, i - begin)));
        }
      }
    } else {
      res.setInteger(stoi(s));
    }
    return res;
  }
};
