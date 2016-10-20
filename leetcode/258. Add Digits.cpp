// Copyright 2016 Qi Wang

// Reference: https://en.wikipedia.org/wiki/Digital_root
// Date: 2016-10-06
class Solution {
 public:
  int addDigits(int num) {
    return num - 9 * ((num - 1) / 9);
  }
};

// Date: 2016-10-06
class Solution {
 public:
  int addDigits(int num) {
    return num % 9 + (num % 9 == 0 && num != 0 ? 9 : 0);
  }
};
