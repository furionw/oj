// Copyright 2017 Qi Wang
// Date: 2017-10-15
class Solution {
 public:
  int repeatedStringMatch(string A, string B) {
    int cnt = 1;
    string inc = A;
    for (; A.size() < B.size(); A += inc) {
      ++cnt;
    }
    if (A.find(B) != string::npos) return cnt;
    return (A += inc).find(B) != string::npos ? cnt + 1 : -1;
  }
};
