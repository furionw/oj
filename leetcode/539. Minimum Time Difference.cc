// Copyright 2017 Qi Wang
// Date: 2017-03-16
class Solution {
 public:
  int findMinDifference(vector<string>& timePoints) {
    if (timePoints.size() <= 1) return 0;
    vector<int> ts;
    for (size_t i = 0; i < timePoints.size(); ++i) {
      size_t split = timePoints[i].find(':');
      ts.push_back(60 * stoi(timePoints[i].substr(0, split))
          + stoi(timePoints[i].substr(split + 1)));
    }
    sort(ts.begin(), ts.end());
    int result = ts.front() + 1440 - ts.back();
    for (size_t i = 0; i + 1 < ts.size(); ++i)
      result = min(result, ts[i + 1] - ts[i]);
    return result;
  }
};
