// Copyright 2016 Qi Wang
// Date: 2016-10-01
class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> res(num + 1, 0);
    for (int offset = 1; offset <= num; offset <<= 1)
      for (int j = 0; j < offset && j + offset <= num; ++j)
        res[j + offset] = res[j] + 1;
    return res;
  }
};
