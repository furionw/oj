// 2025-05-03
// Method 4: similar to method 1
class Solution {
 public:
  int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    int lastNoMeetingDay = 1;
    int result = 0;
    for (const auto& m : meetings) {
      result += max(0, m[0] - lastNoMeetingDay);
      lastNoMeetingDay = max(lastNoMeetingDay, m[1] + 1);
    }
    return result + max(0, days - lastNoMeetingDay + 1);
  }
};

// Method 3: similar to method 2
class Solution {
 public:
  int countDays(int days, vector<vector<int>>& meetings) {
    int result = 0;
    int prev = 0;
    int s = 0;
    map<int, int> cnts;
    for (const auto& m : meetings) {
      ++cnts[m[0]];
      --cnts[m[1] + 1];
    }
    for (const auto& [i, delta] : cnts) {
      if (s == 0) {
        result += i - prev;
      }
      s += delta;
      if (s == 0) {
        prev = i;
      }
    }
    return result + days - prev;
  }
};

// Method 2
class Solution {
 public:
  int countDays(int days, vector<vector<int>>& meetings) {
    int result = 0;
    int prev = 0;
    int s = 0;
    map<int, int> cnts;
    for (const auto& m : meetings) {
      ++cnts[m[0]];
      --cnts[m[1]];
    }
    for (const auto& [i, delta] : cnts) {
      if (s == 0) {
        result += max(0, i - 1 - prev);
      }
      s += delta;
      if (s == 0) {
        prev = i;
      }
    }
    return result + days - prev;
  }
};

// Method 1
struct Point {
  int i;
  int delta;
};

class Solution {
 public:
  int countDays(int days, vector<vector<int>>& meetings) {
    vector<Point> ps;
    for (const auto& m : meetings) {
      ps.push_back(Point {
        .i = m[0],
        .delta = 1
      });
      ps.push_back(Point {
        .i = m[1],
        .delta = -1
      });
    }
    sort(ps.begin(), ps.end(), [](const auto& lhs, const auto& rhs) {
      return lhs.i != rhs.i
          ? lhs.i < rhs.i
          : lhs.delta > rhs.delta;
    });
    int result = 0;
    int prev = 0;
    int balance = 0;
    for (const auto& p : ps) {
      if (balance == 0) {
        result += max(0, p.i - prev - 1);
        ++balance;
      } else {
        balance += p.delta;
        if (balance == 0) {
          prev = p.i;
        }
      }
    }
    return result + days - prev;
  }
};