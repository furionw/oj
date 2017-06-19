// Copyright 2017 Qi Wang
// Date: 2017-06-18
class Solution {
 public:
  int smallestFactorization(int a) {
    if (1 == a) return 1;
    vector<int> init;
    for (int i = 9; i >= 2 && a > 1; --i) {
      while (a % i == 0) {
        a /= i;
        init.push_back(i);
      }
    }
    if (a >= 10) return 0;
    sort(init.begin(), init.end());
    size_t result = 0;
    for (int i = 0; i < init.size(); ++i) {
      result = 10 * result + init[i];
      if (result > INT_MAX) return 0;
    }
    return result;
  }
};
