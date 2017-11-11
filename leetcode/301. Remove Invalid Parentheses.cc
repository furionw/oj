// Copyright 2017 Qi Wang
// Date: 2017-11-10
// Refer to: https://discuss.leetcode.com/topic/34875/easy-short-concise-and-fast-java-dfs-3-ms-solution
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> result;
    Remove(s, 0, 0, {'(', ')'}, &result);
    return result;
  }
 
 private:
  void Remove(string s, int last_i, int last_j, const vector<char>& par,
              vector<string>* result) const {
    for (int i = last_i, cnt = 0; i < s.size(); ++i) {
      if (s[i] == par[0]) ++cnt;
      if (s[i] == par[1]) --cnt;
      if (cnt >= 0) continue;
      for (int j = last_j; j <= i; ++j) {
        // First par[1] in a series of par[1]s
        if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1])) {
          Remove(s.substr(0, j) + s.substr(j + 1), i, j, par, result);
        }
      }
      return;
    }
    reverse(s.begin(), s.end());
    if (par[0] == '(') {
      Remove(s, 0, 0, {')', '('}, result);
    } else {
      result->push_back(s);
    }
  }
};

// Date: 2017-08-12
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    if (s.empty()) return {""};
    int open_to_remove = 0, close_to_remove = 0;
    for (char c : s) {
      if (c == '(') {
        ++open_to_remove;
      } else if (c == ')') {
        if (open_to_remove == 0) {
          ++close_to_remove;
        } else {
          --open_to_remove;
        }
      }
    }
    unordered_set<string> result_set;
    string cur_str;
    F(s, 0, open_to_remove, close_to_remove, 0, &cur_str, &result_set);
    return vector<string>(result_set.begin(), result_set.end());
  }
 
 private:
  void F(const string& s, int idx, int open_to_remove, int close_to_remove,
      int cur, string* cur_str, unordered_set<string>* result_set) const {
    if (idx == s.size()) {
      if (open_to_remove == 0 && close_to_remove == 0) {
        result_set->insert(*cur_str);
      }
    } else {
      if (s[idx] == '(') {
        // drop this element
        if (open_to_remove > 0) {
          F(s, idx + 1, open_to_remove - 1, close_to_remove, cur, cur_str,
            result_set);
        }
        cur_str->push_back(s[idx]);
        F(s, idx + 1, open_to_remove, close_to_remove, cur + 1, cur_str,
          result_set);
        cur_str->pop_back();
      } else if (s[idx] == ')') {
        if (close_to_remove > 0) {
          F(s, idx + 1, open_to_remove, close_to_remove - 1, cur, cur_str,
            result_set);
        }
        if (cur > 0) {
          cur_str->push_back(s[idx]);
          F(s, idx + 1, open_to_remove, close_to_remove, cur - 1, cur_str,
            result_set);
          cur_str->pop_back();
        }
      } else {
        cur_str->push_back(s[idx]);
        F(s, idx + 1, open_to_remove, close_to_remove, cur, cur_str,
          result_set);
        cur_str->pop_back();
      }
    }
  }
};

// Date: 2017-07-03
// This impl is faster than the previous solutions on 2016-10-11 and 2017-03-02
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    int cur = 0, close_tag_to_remove = 0;
    for (char c : s) {
      if ('(' == c) {
        ++cur;
      } else if (')' == c) {
        if (0 == cur) {
          ++close_tag_to_remove;
        } else {
          --cur;
        }
      }
    }
    string str;
    unordered_set<string> result;
    Foo(s, 0, 0, cur, close_tag_to_remove, str, result);
    return vector<string>(result.begin(), result.end());
  }
 
 private:
  void Foo(const string& s, size_t idx, int cur, int open_tag_to_remove,
      int close_tag_to_remove, string& str,
      unordered_set<string>& result) const {
    if (idx == s.size()) {
      if (0 == open_tag_to_remove && 0 == close_tag_to_remove
          && result.count(str) == 0)
        result.insert(str);
    } else {
      if (s[idx] == '(') {
        // remove
        if (open_tag_to_remove > 0)
          Foo(s, idx + 1, cur, open_tag_to_remove - 1, close_tag_to_remove, str,
              result);
        // take
        Foo(s, idx + 1, cur + 1, open_tag_to_remove, close_tag_to_remove,
            str += '(', result);
        str.pop_back();
      } else if (s[idx] == ')') {
        // remove
        if (close_tag_to_remove > 0)
          Foo(s, idx + 1, cur, open_tag_to_remove, close_tag_to_remove - 1, str,
              result);
        // take
        if (cur > 0) {
          Foo(s, idx + 1, cur - 1, open_tag_to_remove, close_tag_to_remove,
              str += ')', result);
          str.pop_back();
        }
      } else {
        // take
        Foo(s, idx + 1, cur, open_tag_to_remove, close_tag_to_remove,
              str += s[idx], result);
        str.pop_back();
      }
    }
  }
};

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
