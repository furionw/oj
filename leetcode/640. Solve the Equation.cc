// Copyright 2017 Qi Wang
// Date: 2017-06-08
class Solution {
 public:
  string solveEquation(string equation) {
    size_t equal = equation.find('=');
    auto left = equation.substr(0, equal);
    auto right = equation.substr(equal + 1);
    int64_t x_cnt = 0;
    int64_t val = 0;
    // left
    auto temp = Foo(left);
    x_cnt += temp.first;
    val -= temp.second;
    // right
    temp = Foo(right);
    x_cnt -= temp.first;
    val += temp.second;
    if (x_cnt == 0 && val == 0) {
      return "Infinite solutions";
    } else if (x_cnt == 0 && val != 0) {
      return "No solution";
    } else {
      return string("x=") + to_string(val / x_cnt);
    }
  }

 private:
  pair<int64_t, int64_t> Foo(const string& str) const {
    int64_t x_cnt = 0;
    int64_t val = 0;
    size_t pos = 0;
    for (size_t i = 0; i < str.size(); pos = i) {
      int sign = 1;
      if (IsOp(str[i])) {
        sign = str[i] == '+' ? 1 : -1;
        ++i;
      }
      // x
      if (str[i] == 'x') {
        x_cnt += sign;
        ++i;
      // digit
      } else {
        for (; i < str.size() && IsDigit(str[i]); ++i) {}
        if (i == str.size() || IsOp(str[i])) {
          val += stoi(str.substr(pos, i - pos));
        // x
        } else {
          x_cnt += stoi(str.substr(pos, i - pos));
          ++i;
        }
      }
    }
    // cout << x_cnt << ", " << val << endl;
    return {x_cnt, val};
  }

  bool IsDigit(char c) const {
    return '0' <= c && c <= '9';
  }

  bool IsOp(char c) const {
    return '+' == c || '-' == c;
  }
};