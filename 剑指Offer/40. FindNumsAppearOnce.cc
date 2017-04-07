// Copyright 2017 Qi Wang
// Date: 2017-04-07
class Solution {
 public:
  void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int acc = 0;
    for (int num : data) acc ^= num;
    int mask = 1;
    for (; !(mask & acc); mask <<= 1) {}
    *num1 = *num2 = 0;
    for (int num : data) {
      if (num & mask) {
        *num1 ^= num;
      } else {
        *num2 ^= num;
      }
    }
  }
};
