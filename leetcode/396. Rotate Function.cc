// Copyright 2016 Qi Wang
// Date: 2016-10-25
class Solution {
 public:
  int maxRotateFunction(vector<int> A) {
    if (A.empty()) return 0;
    int sum = 0;
    for (int a : A) sum += a;
    // F(0)
    int res = 0;
    for (size_t i = 0; i < A.size(); ++i) res += i * A[i];
    // F(1) ... F(n-1)
    int pre = res;
    for (size_t i = 1; i <= A.size() - 1; ++i) {
      pre += sum - int(A.size()) * A[A.size() - i];
      res = max(res, pre);
    }
    return res;
  }
};
