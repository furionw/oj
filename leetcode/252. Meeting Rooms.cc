// Copyright 2017 Qi Wang
// Date: 2017-08-29
class Solution {
 public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    if (intervals.empty()) return true;
    sort(intervals.begin(), intervals.end(),
         [](const Interval& lhs, const Interval& rhs) {
           return lhs.start != rhs.start ? lhs.start < rhs.start
                                         : lhs.end < rhs.end;
         });
    int prev = intervals.front().end;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start < prev) {
        return false;
      } else {
        prev = intervals[i].end;
      }
    }
    return true;
  }
};

// Date: 2017-07-21
class Solution {
 public:
  bool canAttendMeetings(vector<Interval>& inters) {
    sort(inters.begin(), inters.end(),
      [](const Interval& lhs, const Interval& rhs) {
        return lhs.start != rhs.start ? lhs.start < rhs.start
            : lhs.end < rhs.end;
      });
    for (size_t i = 0; i + 1 < inters.size(); ++i) {
      if (inters[i].end > inters[i + 1].start) return false;
    }
    return true;
  }
};

// Date: 2017-02-15
class Solution {
 private:
  using I = Interval;

 public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const I& lhs, const I& rhs) {
      return lhs.start != rhs.start
          ? lhs.start < rhs.start : lhs.end < rhs.end;
    });
    for (size_t i = 0; i + 1 < intervals.size(); ++i)
      if (intervals[i].end > intervals[i + 1].start)
        return false;
    return true;
  }
};
