// 2025-07-27
class Solution {
 public:
  long long taskSchedulerII(vector<int>& tasks, int space) {
    unordered_map<int, long long> next;
    long long d = 1;
    for (int t : tasks) {
      d = max(d, next[t]);
      next[t] = d + space + 1;
      ++d;
    }
    return d - 1;
  }
};
