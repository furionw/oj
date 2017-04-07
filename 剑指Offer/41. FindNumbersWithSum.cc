// Copyright 2017 Qi Wang
// Date: 2017-04-07
class Solution {
 public:
  vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    int l = 0, r = array.size() - 1;
    vector<int> result;
    while (l < r) {
      if (array[l] + array[r] == sum) {
        return {array[l], array[r]};
      } else if (array[l] + array[r] < sum) {
        ++l;
      } else {
        --r;
      }
    }
    return {};
  }
};

// Follow up
// Refer to the book
class Solution {
 public:
  vector<vector<int>> FindContinuousSequence(int sum) {
    int small = 1, big = 2, acc = 3;
    vector<vector<int>> result;
    while (small <= (sum >> 1)) {
      while (acc < sum) acc += ++big;
      while (acc > sum) acc -= small++;
      if (acc == sum) {
        vector<int> vt;
        for (int i = small; i <= big; ++i) vt.push_back(i);
        result.push_back(vt);
        acc -= small++;
      }
    }
    return result;
  }
};
