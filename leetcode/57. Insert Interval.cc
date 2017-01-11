// Copyright 2017 Qi Wang
// Date: 2017-01-11
class Solution {
 public:
  // intervals: a non-overlapping intervals
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    if (intervals.empty()) {
      return vector<Interval>(1, newInterval);
    } else {
      vector<Interval> result;
      auto it = intervals.begin();
      for (; it != intervals.end() && it->end < newInterval.start; ++it)
        result.push_back(*it);
      for (; it != intervals.end() && it->start <= newInterval.end; ++it) {
        newInterval.start = min(newInterval.start, it->start);
        newInterval.end = max(newInterval.end, it->end);
      }
      result.push_back(newInterval);
      for (; it != intervals.end(); ++it)
        result.push_back(*it);
      return result;
    }
  }
};

// Date: ...
class Solution 
{
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
  {
    vector<Interval> ret;

    for (auto it = intervals.begin(); it != intervals.end(); ++ it)
    {
      if (it->end<newInterval.start || it->start>newInterval.end)
      {
        ret.push_back( *it );
      } else if (it->start<newInterval.start &&
        it->end>=newInterval.start && it->end<=newInterval.end)
      {
        newInterval.start = it->start;
      } else if (it->end>newInterval.end &&
        it->start>=newInterval.start && it->start<=newInterval.end)
      {
        newInterval.end = it->end;
      } else if (it->start<=newInterval.start && it->end>=newInterval.end)
      {
        newInterval.start = it->start;
        newInterval.end = it->end;
      }
    }
    auto it = ret.begin();
    for ( ; it != ret.end(); ++ it)
    {
      if (it->start > newInterval.end)
      {
        intervals.insert(it, newInterval);
        break;
      }
    }
    if (it == ret.end())
    {
      ret.push_back( newInterval );
    }

    return ret;
  }
};