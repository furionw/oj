// Copyright 2017 Qi Wang
// Date: 2017-08-29
// Case 1: [[0, 1], [1, 2], [1, 3]]
class Solution {
 public:
  int minMeetingRooms(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(),
         [](const Interval& lhs, const Interval& rhs) {
           return lhs.start != rhs.start ? lhs.start < rhs.start
                                         : lhs.end < rhs.end;
         });
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(intervals.front().end);
    for (int i = 1; i < intervals.size(); ++i) {
      if (pq.top() <= intervals[i].start) {
        pq.pop();
      }
      pq.push(intervals[i].end);
    }
    return pq.size();
  }
};

// Date: 2017-07-22
class Solution {
 public:
  int minMeetingRooms(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    vector<int> room_endtimes(1, INT_MIN);
    sort(intervals.begin(), intervals.end(),
        [](const Interval& lhs, const Interval& rhs) {
          return lhs.start != rhs.start ? lhs.start < rhs.start
              : lhs.end < rhs.end;
        });
    for (const auto& inter : intervals) {
      bool find = false;
      for (size_t i = 0; i < room_endtimes.size(); ++i) {
        if (inter.start >= room_endtimes[i]) {
          find = true;
          room_endtimes[i] = inter.end;
          break;
        }
      }
      if (!find) room_endtimes.push_back(inter.end);
    }
    return room_endtimes.size();
  }
};

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
