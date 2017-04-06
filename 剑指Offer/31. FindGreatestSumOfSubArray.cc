// Copyright 2017 Qi Wang
// Date: 2017-04-06
class Solution {
 public:
  int FindGreatestSumOfSubArray(vector<int> array) {
    if (array.empty()) return 0;
    int result = INT_MIN, acc = 0;
    for (int num : array) {
      result = max(result, acc += num);
      if (acc < 0) acc = 0;
    }
    return result;
  }
};
