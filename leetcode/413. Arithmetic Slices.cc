// Copyright 2016 Qi Wang
// Date: 2016-11-02
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    if (A.size() <= 2) return 0;
    list<int> cnts;
    int cnt = 2, diff = A[1] - A[0];
    for (size_t i = 2; i < A.size(); ++i)
      if (A[i] - A[i - 1] == diff) {
        ++cnt;
      } else {
        diff = A[i] - A[i - 1];
        if (cnt > 2) cnts.push_back(cnt);
        cnt = 2;
      }
    if (cnt > 2) cnts.push_back(cnt);
    return accumulate(cnts.begin(), cnts.end(), 0, [](int sum, int cnt) {
      return sum + (cnt - 1) * (cnt - 2) / 2;
    });
  }
};
