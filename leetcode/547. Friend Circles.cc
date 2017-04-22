// Copyright 2017 Qi Wang
// Date: 2017-04-22
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    if (M.empty()) return 0;
    vector<bool> visited(M.size(), false);
    queue<int> q;
    int circle = 0;
    for (int i = 0; i < M.size(); ++i)
      if (!visited[i]) {
        ++circle;
        visited[i] = true;
        q.push(i);
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int v = 0; v < M.size(); ++v)
            if (M[u][v] && !visited[v]) {
              visited[v] = true;
              q.push(v);
            }
        }
      }
    return circle;
  }
};
