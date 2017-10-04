// Copyright 2017 Qi Wang
// Date: 2017-10-03
class Solution {
 public:
  int singleNumber(vector<int> &A) {
    return accumulate(A.begin(), A.end(), 0, [](int acc, int cur) {
      return acc ^ cur;
    });
  }
};
