// 2025-07-08
class Solution {
 public:
  int maxTwoEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end());
    int n = events.size();
    vector<int> maxs(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
      maxs[i] = max(events[i][2], maxs[i + 1]);
    }
    int result = maxs[0];
    for (int i = n - 2; i >= 0; --i) {
      auto it = upper_bound(events.begin() + i + 1, events.end(), events[i][1],
          [](int end, const auto& e) {
            return end < e[0];
          });
      result = max(result, events[i][2] + maxs[it - events.begin()]);
    }
    return result;
  }
};
