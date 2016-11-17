// Copyright 2016 Qi Wang
// Refer to :
//  1. http://bookshadow.com/weblog/2016/11/06/leetcode-arithmetic-slices-ii-subsequence/
//    - python version
//  2. http://www.cnblogs.com/grandyang/p/6057934.html
//    - cpp implementation. Pay attention to its INT_MAX & INT_MIN judge
// Date: 2016-11-17
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    if (A.size() < 3) return 0;
    unordered_map<int, int> deltaTbl[A.size()];
    int res = 0;
    for (size_t i = 1; i < A.size(); ++i)
      for (size_t j = 0; j < i; ++j) {
        auto delta = static_cast<int64_t>(A[i]) - A[j];
        if (delta > INT_MAX || delta < INT_MIN) continue;  // judge here!
        deltaTbl[i][delta] += 1;  // += 1 instead of = 1
        if (deltaTbl[j].find(delta) != deltaTbl[j].end()) {
          deltaTbl[i][delta] += deltaTbl[j][delta];
          res += deltaTbl[j][delta];
        }
      }
    return res;
  }
};
