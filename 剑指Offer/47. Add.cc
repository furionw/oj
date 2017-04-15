// Copyright 2017 Qi Wang
// Date: 2017-04-15
// Refer to the book
class Solution {
 public:
  int Add(int num1, int num2) const {
    int sum;
    do {
      sum = num1 ^ num2;
      num2 = (num1 & num2) << 1;  // num2 == carry now
      num1 = sum;
    } while (num2 != 0);
    return sum;
  }
};
