// Copyright 2017 Qi Wang
// Date: 2017-02-23
class Solution {
 public:
  string convertToBase7(int num) {
    bool negative = num < 0;
    num = abs(num);
    string result;
    do {
      result += num % 7 + '0';
    } while ((num /= 7) != 0);
    reverse(result.begin(), result.end());
    return !negative ? result : "-" + result;
  }
};
