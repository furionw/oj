// Copyright 2017 Qi Wang
// Date: 2017-06-04
// Refer to: watashi's solution
class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int consecutive_zero_cnt = 1, result = 0;
    for (int i : flowerbed) {
      if (0 == i) {
        ++consecutive_zero_cnt;
      } else {
        result += (consecutive_zero_cnt - 1) / 2;
        consecutive_zero_cnt = 0;
      }
    }
    return (result + consecutive_zero_cnt / 2) >= n;
  }
};

// Date: 2017-06-04
class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    vector<int> pos;
    for (int i = 0; i < flowerbed.size(); ++i)
      if (1 == flowerbed[i])
        pos.push_back(i);
    pos.push_back(flowerbed.size() + 1);
    int acc = 0, prev = -2;
    for (int i = 0; i < pos.size(); ++i) {
      if (pos[i] - prev - 2 > 1)
        acc += (pos[i] - prev - 2) / 2;
      prev = pos[i];
    }
    return acc >= n;
  }
};
