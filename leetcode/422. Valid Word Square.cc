// Copyright 2016 Qi Wang
// Date: 2016-12-29
class Solution {
 public:
  bool validWordSquare(vector<string>& words) {
    int vCnt[words.size()] = {0};  // vertical counter
    for (size_t j = 0; j < words.size(); ++j)
      for (size_t i = 0; i < words.size() && words[i].size() > j;
          ++vCnt[i++]) {}
    for (size_t k = 0; k < words.size(); ++k) {
      if (words[k].size() != vCnt[k]) return false;
      for (size_t idx = 0; idx < vCnt[k]; ++idx)
        // kth row, kth column
        if (words[idx][k] != words[k][idx]) return false;
    }
    return true;
  }
};
