// 2025-06-18
class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    priority_queue<int> workers;
    for (int w: worker) {
      workers.push(w);
    }
    priority_queue<pair<int, int>> jobs;
    for (int i = 0; i < profit.size(); ++i) {
      jobs.emplace(profit[i], difficulty[i]);
    }
    int result = 0;
    while (!jobs.empty() && !workers.empty()) {
      auto [p, d] = jobs.top();
      jobs.pop();
      while (!workers.empty() && workers.top() >= d) {
        workers.pop();
        result += p;
      }
    }
    return result;
  }
};
