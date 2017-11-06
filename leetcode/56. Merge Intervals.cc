// Copyright 2017 Qi Wang
// Date: 2017-11-06
// Your thought becomes sharp at this time and You do better than what you did
// on 2017-07-21 :)
class Solution {
 public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.size() < 2) return intervals;
    sort(intervals.begin(), intervals.end(),
         [](const Interval& lhs, const Interval& rhs) {
           return lhs.start < rhs.start;
         });
    int start = intervals.front().start, end = intervals.front().end;
    vector<Interval> result;
    for (int i = 1; i < intervals.size(); ++i) {
      if (end < intervals[i].start) {
        result.emplace_back(start, end);
        start = intervals[i].start;
        end = intervals[i].end;
      } else {
        end = max(end, intervals[i].end);
      }
    }
    result.emplace(start, end);
    return result;
  }
};

// Date: 2017-07-21
class Solution {
 public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end(),
      [](const Interval& lhs, const Interval& rhs) {
        return lhs.start != rhs.start ? lhs.start < rhs.start
            : lhs.end < rhs.end;
      });
    vector<Interval> result;
    int start = intervals.front().start,
        end = intervals.front().end;
    for (size_t i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start > end) {
        result.emplace_back(start, end);
        start = intervals[i].start;
        end = intervals[i].end;
      } else {
        end = max(end, intervals[i].end);
      }
    }
    result.emplace_back(start, end);
    return result;
  }
};

// Date: 2017-01-02
// Last modified: 2017-01-11
class Solution {
  using I = Interval;

 public:
  vector<I> merge(vector<I>& intervals) {
    if (intervals.empty()) return vector<I>();
    sort(intervals.begin(), intervals.end(), [](const I& lhs, const I& rhs) {
      return lhs.start != rhs.start ? lhs.start < rhs.start : lhs.end < rhs.end;
    });
    vector<Interval> res(1, intervals.front());
    for (size_t i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start > res.back().end) {
        res.push_back(intervals[i]);
      } else {
        res.back().end = max(intervals[i].end, res.back().end);  // Last modified: 2017-01-11
      }
    }
    return res;
  }
};

// Date: ...
bool cmp(const Interval& a, const Interval& b)
{
  if (a.start != b.start)
  {
    return a.start < b.start;
  } else 
  {
    return a.end < b.end;
  }
}

class Solution 
{
public:
    vector<Interval> merge(vector<Interval> &intervals) 
    {
      if (intervals.empty() == true)
      {
        return vector<Interval>();
      }
      vector<Interval> ret;
      Interval pre = intervals[0];

      sort (intervals.begin(), intervals.end(), cmp);
      for (size_t i = 1; i < intervals.size(); ++ i)
      {
        if (pre.end < intervals[i].start)
        {
          ret.push_back( pre );
          pre = intervals[i];
        } else if (pre.end>=intervals[i].start && pre.end<=intervals[i].end)
        {
          pre.end = intervals[i].end;
        }
      }
      ret.push_back( pre );

      return ret;
    }
};