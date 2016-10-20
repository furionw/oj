// Copyright 2016 Qi Wang
// Date: 2016-10-11
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    this->s = s;  // You cannot write "s = s;" here!!!
    int minRemove = 0, parentheseCnt = 0;
    for (char c : s) {
      if (c == '(') {
        ++parentheseCnt;
      } else if (c == ')') {
        if (parentheseCnt == 0) {
          ++minRemove;
        } else {
          --parentheseCnt;
        }
      }
    }
    minRemove += parentheseCnt;
    recursive(0, 0, minRemove, "");
    return vector<string>(res.begin(), res.end());
  }

 private:
  void recursive(size_t i, int parentheseCnt, int removeCnt, string cur) {
    if (i == s.size()) {
      if (parentheseCnt == 0) res.insert(cur);
      return;
    }

    if (s[i] == '(') {
      recursive(i + 1, parentheseCnt + 1, removeCnt, cur + '(');
      if (removeCnt > 0)
        recursive(i + 1, parentheseCnt, removeCnt - 1, cur);
    } else if (s[i] == ')') {
      if (parentheseCnt > 0)
        recursive(i + 1, parentheseCnt - 1, removeCnt, cur + ')');
      if (removeCnt > 0)
        recursive(i + 1, parentheseCnt, removeCnt - 1, cur);
    } else {
      recursive(i + 1, parentheseCnt, removeCnt, cur + s[i]);
    }
  }

  string s;
  unordered_set<string> res;
};
