// Copyright 2017 Qi Wang
// Date: 2017-08-12
class Solution {
 public:
  int newInteger(int n) {
    int result = 0;
    for(int i = 0; n > 0; n /= 9, ++i) {
      result += (n % 9) * pow(10, i);
    }
    return result;
  }
};
