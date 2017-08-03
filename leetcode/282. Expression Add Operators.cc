// Copyright 2017 Qi Wang
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
