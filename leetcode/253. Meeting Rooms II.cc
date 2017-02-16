// Copyright 2017 Qi Wang
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
