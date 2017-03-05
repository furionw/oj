// Copyright 2017 Qi Wang
// Date: 2017-03-02
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> result;
    // init result with an empty string
    result.insert("");
    f(s, 0, "", 0, result);
    return vector<string>(result.begin(), result.end());
  }

 private:
  void f(const string& s, size_t idx, const string& cur, int balance,
      unordered_set<string>& result) const {
    if (idx == s.size()) {
      if (balance == 0) {
        if (cur.size() > result.begin()->size()) {
          result.clear();
          result.insert(cur);
        } else if (cur.size() == result.begin()->size()) {
          result.insert(cur);
        }
      }
      return;
    }
    if (s[idx] != '(' && s[idx] != ')') {
      f(s, ++idx, cur + s[idx], balance, result);
    } else {
      f(s, idx + 1, cur, balance, result);
      if (s[idx] == '(') {
        f(s, ++idx, cur + '(', ++balance, result);
      } else if (s[idx] == ')' && balance > 0) {
        f(s, ++idx, cur + ')', --balance, result);
      }
    }
  }
};

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
