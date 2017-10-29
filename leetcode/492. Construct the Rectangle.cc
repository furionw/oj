// Copyright 2017 Qi Wang
// Date: 2017-10-26
class Solution {
 public:
  vector<int> constructRectangle(int area) {
    for (int w = sqrt(area); w >= 1; --w) {
      if (area % w == 0) {
        return {area / w, w};
      }
    }
    return {0, 0};
  }
};

// Date: 2017-02-06
class Solution {
 public:
  vector<int> constructRectangle(int area) {
    for (int w = sqrt(area); w >= 1; --w)
      if (area % w == 0)
        return {area / w, w};
    return {-1, -1};
  }
};
