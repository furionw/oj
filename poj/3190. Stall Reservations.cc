// Copyright 2017 Qi Wang
// Date: 2017-05-11
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

struct Interval {
  Interval() {}
  Interval(int s, int e, int i) : start(s), end(e), id(i) {}
  bool operator <(const Interval& rhs) {
    if (start != rhs.start) {
      return start < rhs.start;
    } else if (end != rhs.end) {
      return end < rhs.end;
    } else {
      return id < rhs.id;
    }
  }
  int start, end, id;
};

struct Stall {
  Stall(int p, int i) : pos(p), id(i) {}
  int pos;
  int id;
};

struct comp {
  bool operator ()(const Stall& lhs, const Stall& rhs) {
    return lhs.pos != rhs.pos ? lhs.pos > rhs.pos : lhs.id > rhs.id;
  }
};

int main() {
  int n;
  cin >> n;
  vector<Interval> intervals;
  for (int i = 0; i < n; ++i) {
    int start, end;
    cin >> start >> end;
    intervals.push_back(Interval(start, end, i));
  }
  sort(intervals.begin(), intervals.end());
  priority_queue<Stall, vector<Stall>, comp> q;
  q.push(Stall(0, 1));
  vector<int> result(n);
  for (int i = 0; i < n; ++i) {
    if (q.top().pos < intervals[i].start) {
      Stall stall = q.top();
      q.pop();
      stall.pos = intervals[i].end;
      q.push(stall);
      result[intervals[i].id] = stall.id;
    } else {
      Stall stall(intervals[i].end, q.size() + 1);
      q.push(stall);
      result[intervals[i].id] = stall.id;
    }
  }
  cout << q.size() << endl;
  for (int i = 0; i < n; ++i)
    cout << result[i] << endl;
}
