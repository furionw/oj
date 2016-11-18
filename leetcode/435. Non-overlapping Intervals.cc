// Copyright 2016 Qi Wang
// Method 2
// Greedy -- CLRS, activity selection problem
// Date: 2016-11-16
class Solution {
 public:
  int eraseOverlapIntervals(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(),
        [](const Interval& lhs, const Interval& rhs) {
          return lhs.end < rhs.end;
        });
    int n = static_cast<int>(intervals.size());
    int tot = 1, pre = 0;
    for (int i = 1; i < n; ++i)
      if (intervals[i].start >= intervals[pre].end) {
        pre = i;
        ++tot;
      }
    return n - tot;
  }
};

// Method 1
// Dynamic programming
// Date: 2016-11-16
class Solution {
 public:
  int eraseOverlapIntervals(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(),
        [](const Interval& lhs, const Interval& rhs) {
          return lhs.start < rhs.start;
        });
    int n = static_cast<int>(intervals.size());
    int dp[n];
    fill(dp, dp + n, 1);
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (intervals[i].start >= intervals[j].end)
          dp[i] = max(dp[i], dp[j] + 1);
    return n - dp[n - 1];
  }
};
