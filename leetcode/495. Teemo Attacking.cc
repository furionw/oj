// Copyright 2017 Qi Wang
// Date: 2017-03-17
// Refer to: https://discuss.leetcode.com/topic/77072/short-o-n-c-solution
class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int result = 0, expected = 0;
    for (int timepoint : timeSeries) {
      result += duration - (timepoint < expected) * (expected - timepoint);
      expected = timepoint + duration;
    }
    return result;
  }
};

// Date: 2017-03-17
class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if (timeSeries.empty()) return 0;
    int result = 0;
    int prev = timeSeries.front();
    for (int i = 1; i < timeSeries.size(); ++i) {
      int timepoint = timeSeries[i];
      if (prev + duration > timepoint) {
        result += timepoint - prev;
      } else {
        result += duration;
      }
      prev = timepoint;
    }
    return result + duration;
  }
};
