// Copyright 2017 Qi Wang
// Date: 2017-08-16
// The solution on 2017-01-11 is much better
class Solution {
 public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> result;
    auto itr = intervals.begin();
    for (; itr != intervals.end() && itr->end < newInterval.start; ++itr) {
      result.push_back(*itr);
    }
    if (itr == intervals.end()) {
      result.push_back(newInterval);
      return result;
    }
    int start = itr->start;
    while (itr + 1 != intervals.end()
           && newInterval.end >= (itr + 1)->start) {
      ++itr;
    }
    if (newInterval.end >= itr->start) {
      result.emplace_back(min(start, newInterval.start),
                          max(itr->end, newInterval.end));
      ++itr;
    } else {
      result.push_back(newInterval);
      result.push_back(*itr);
      ++itr;
    }
    for (; itr != intervals.end(); ++itr) {
      result.push_back(*itr);
    }
    return result;
  }
};

// Date: 2017-07-25
// I more appreciate the solution on 2017-01-11
class Solution {
 public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    if (intervals.empty()) return {newInterval};
    auto itr = find_if(intervals.begin(), intervals.end(),
        [newInterval](const Interval& elem) {
          return elem.start > newInterval.start;
        });
    intervals.insert(itr, newInterval);
    return MergeIntervals(intervals);
  }

 private:
  vector<Interval> MergeIntervals(const vector<Interval>& inters) const {
    vector<Interval> result;
    int start = inters[0].start, end = inters[0].end;
    for (int i = 1; i < inters.size(); ++i) {
      if (inters[i].start > end) {
        result.emplace_back(start, end);
        start = inters[i].start;
        end = inters[i].end;
      } else {
        end = max(end, inters[i].end);
      }
    }
    result.emplace_back(start, end);
    return result;
  }
};

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