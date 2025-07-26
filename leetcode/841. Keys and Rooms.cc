// 2025-07-25
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    unordered_set<int> q {0};
    while (!q.empty()) {
      --n;
      int u = *q.begin();
      q.erase(u);
      visited[u] = true;
      for (int v : rooms[u]) {
        if (!visited[v]) {
          q.insert(v);
        }
      }
    }
    return n == 0;
  }
};
