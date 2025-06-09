// 2025-06-07
class Solution {
 public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<int> ins(n, 0);
    vector<vector<int>> nexts(n, vector<int>{});
    for (const auto& r : relations) {
      ++ins[r[1] - 1];
      nexts[r[0] - 1].push_back(r[1] - 1);
    }

    queue<int> q;
    int result = 0;
    vector<int> takenTime(n, 0);
    for (int i = 0; i < n; ++i) {
      takenTime[i] = time[i];
      result = max(result, takenTime[i]);
      if (ins[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : nexts[u]) {
        takenTime[v] = max(takenTime[v], takenTime[u] + time[v]);
        result = max(result, takenTime[v]);
        if (--ins[v] == 0) {
          q.push(v);
        }
      }
    }

    return result;
  }
};