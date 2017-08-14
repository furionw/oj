// Copyright 2017 Qi Wang
// Date: 2017-08-13
class Solution {
 public:
  // assume all operands are within [INT_MIN, INT_MAX]
  vector<string> addOperators(string s, int target) {
    vector<string> result;
    for (int i = 0; i < s.size(); ++i) {
      string str = s.substr(0, i + 1);
      int val = stol(str);
      if (to_string(val) != str) break;
      F(s, i + 1, val, val, 'x', target, str, &result);
    }
    return result;
  }
 
 private:
  void F(const string& s, int idx, int val, int prev, char prev_op,
      int target, const string& cur, vector<string>* result) const {
    if (idx == s.size() && val == target) {
      result->push_back(cur);
      return;
    }
    for (int i = idx; i < s.size(); ++i) {
      string str = s.substr(idx, i - idx + 1);
      int num = stol(str);
      if (to_string(num) != str) break;
      F(s, i + 1, val + num, num, '+', target, cur + "+" + str, result);
      F(s, i + 1, val - num, num, '-', target, cur + "-" + str, result);
      int val_for_mul = prev_op == '+'
          ? val - prev + prev * num
          : (prev_op == '-'
                ? val + prev - prev * num
                : val * num);
      F(s, i + 1, val_for_mul, prev * num, prev_op, target, cur + "*" + str,
          result);
    }
  }
};

// Date: 2017-08-02
// Refer to: https://discuss.leetcode.com/topic/24478/17-lines-solution-dfs-c
class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> result;
    for (int len = 1; len <= num.size(); ++len) {
      string elem = num.substr(0, len);
      int64_t val = stol(elem);
      if (to_string(val) != elem) break;
      F(num, len, elem, val, 0, '#', target, &result);
    }
    return result;
  }

 private:
  void F(
      const string& num, int pos, string expr, int64_t cur, int64_t prev,
      char op, int target, vector<string>* result) const {
    if (pos == num.size() && cur == target) {
      result->push_back(expr);
    } else {
      for (int i = pos + 1; i <= num.size(); ++i) {
        string elem = num.substr(pos, i - pos);
        int64_t val = stol(elem);
        if (to_string(val) != elem) break;
        F(num, i, expr + '+' + elem, cur + val, val, '+', target, result);
        F(num, i, expr + '-' + elem, cur - val, val, '-', target, result);
        F(num, i, expr + '*' + elem,
          op == '+'
              ? (cur - prev + prev * val)
              : (op == '-' ? cur + prev - prev * val : cur * val),
          prev * val, op, target, result);
      }
    }
  }
};
