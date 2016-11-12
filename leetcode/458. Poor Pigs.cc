// Copyright 2016 Qi Wang
// Refer to: http://bookshadow.com/weblog/2016/11/08/leetcode-poor-pigs/
// My feeling: tough and lack of proofs
// Date: 2016-11-12
class Solution {
 public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int testCnt = minutesToTest / minutesToDie;
    return ceil(log(buckets) / log(1 + testCnt));
  }
};
