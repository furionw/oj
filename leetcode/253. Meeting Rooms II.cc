// Copyright 2017 Qi Wang
// Date: 2017-07-05
class Solution {
 public:
  int minMeetingRooms(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(),
        [](const Interval& lhs, const Interval& rhs) {
          return lhs.start < rhs.start;
        });
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(intervals.front().end);
    for (size_t i = 1; i < intervals.size(); ++i) {
      if (pq.top() <= intervals[i].start)
        pq.pop();
      pq.push(intervals[i].end);
    }
    return pq.size();
  }
};

// Date: 2017-02-16
class Solution {
 private:
  using I = Interval;

 public:
  int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const I& lhs, const I& rhs) {
      return lhs.start != rhs.start
          ? lhs.start < rhs.start : lhs.end < rhs.end;
    });
    vector<int> rooms;
    for (const I& interval : intervals) {
      bool find = false;
      for (int& room : rooms) {
        if (room <= interval.start) {
          room = interval.end;
          find = true;
          break;
        }
      }
      if (!find) rooms.push_back(interval.end);
    }
    return rooms.size();
  }
};
