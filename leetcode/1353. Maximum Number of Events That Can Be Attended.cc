// 2025-05-19
class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;
    int last = 0;
    int i = 0;
    int n = events.size();
    sort(events.begin(), events.end());
    while (i < n || !pq.empty()) {
      if (pq.empty()) {
        last = events[i][0];
      }
      for (; i < n && events[i][0] <= last; ++i) {
        pq.push(events[i][1]);
      }
      pq.pop();
      ++result;
      ++last;
      for (; !pq.empty() && pq.top() < last; pq.pop()) {}
    }
    return result;
  }
};
