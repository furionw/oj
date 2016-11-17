// Copyright 2016 Qi Wang
// Date: 2016-11-17
class Solution {
 public:
  bool isUgly(int num) {
    if (num <= 0) return false;
    for (; num % 2 == 0; num >>= 1) {}
    for (; num % 3 == 0; num /= 3) {}
    for (; num % 5 == 0; num /= 5) {}
    return num == 1;
  }
};

// Date: 2015-09
class Solution 
{
public:
  bool isUgly(int num) 
  {
    if (num <= 0)
    {
      return false;
    }

    for (; num % 2 == 0; num /= 2) {}
    for (; num % 3 == 0; num /= 3) {}
    for (; num % 5 == 0; num /= 5) {}
      
    return num == 1;
  }
};