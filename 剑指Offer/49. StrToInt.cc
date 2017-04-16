// Copyright 2017 Qi Wang
// Date: 2017-04-16
// "Similar" to LC. 8
class Solution {
 public:
  int StrToInt(string str) {
    bool positive = true;
    bool find_sign = false;
    bool find_digit = false;
    int result = 0;
    for (char c : str) {
      if (c == '+') {
        // duplicate sign
        if (find_sign) {
          return 0;
        } else {
          find_sign = true;
        }
      } else if (c == '-') {
        if (find_sign) {
          return 0;
        } else {
          find_sign = true;
          positive = false;
        }
      } else if ('0' <= c && c <= '9') {
        find_digit = true;
        if (positive && (result > INT_MAX / 10
            || (result == INT_MAX / 10 && c - '0' >= 7))) {
          return INT_MAX;
        } else if (!positive && (result > INT_MAX / 10
            || (result == INT_MAX / 10 && c - '0' >= 8))) {
          return INT_MIN;
        }
        result = result * 10 + c - '0';
      } else if (c == ' ') {
        // error case
        if (find_sign || find_digit) return 0;
      } else {
        return 0;
      }
    }
    return positive ? result : -result;
  }
};
