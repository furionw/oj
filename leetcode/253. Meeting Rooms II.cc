// 2025-07-08
class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& ints) {
    sort(ints.begin(), ints.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;
    for (const auto& v : ints) {
      for (; !pq.empty() && pq.top() <= v[0]; pq.pop()) {}
      pq.push(v[1]);
      result = max(result, int(pq.size()));
    }
    return result;
  }
};

// Date: 2017-10-25
// Case 1: []
// Case 2: [[1, 3], [3, 5], [4, 6]]
class Solution {
 public:
  int minMeetingRooms(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(),
         [](const Interval& lhs, const Interval& rhs) {
           // It's necessary to sort the intervals by its start firstly.
           // Otherwises this impl will fail in the case of
           // [[4, 9], [2, 15], [16, 23], [9, 29], [36, 45]] (increasing 'end')
           // [[2, 15], [4, 9], [9, 29], [16, 23], [36, 45]] (increasing 'start')
           return lhs.start != rhs.start ? lhs.start < rhs.start
                                         : lhs.end < rhs.end;
         });
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(intervals.front().end);
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start >= pq.top()) {
        pq.pop();
      }
      pq.push(intervals[i].end);
    }
    return pq.size();
  }
};

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
