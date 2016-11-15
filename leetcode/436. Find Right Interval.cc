// Copyright 2016 Qi Wang
// Tag: Binary search.
// Note that the orders of two arguments in lower_bound() & upper_bound()
// are different !!! And you gotta have a thorough understanding of how those
// two function.
// Date: before dawn on 2016-11-16
class Solution {
 public:
  vector<int> findRightInterval(vector<Interval>& intervals) {
    int idxs[intervals.size()];
    int n = intervals.size();
    for (int i = 0; i < n; ++i)
      idxs[i] = i;
    sort(idxs, idxs + n, [&intervals](int lhs, int rhs) {
      return intervals[lhs].start < intervals[rhs].start;
    });
    vector<int> res(intervals.size());
    for (int i = 0; i < n; ++i) {
      auto it = lower_bound(idxs + i + 1, idxs + n, idxs[i],
          [&intervals](int elem, int val) {
            return intervals[val].end > intervals[elem].start;
          });
      res[idxs[i]] = it != idxs + n ? *it : -1;
    }
    return res;
  }
};
