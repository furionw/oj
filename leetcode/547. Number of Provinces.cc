// 2025-05-06
// Method 1: union-find
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    n = isConnected.size();
    parents = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isConnected[i][j]) {
          merge(i, j);
        }
      }
    }
    unordered_set<int> provinces;
    for (int i = 0; i < n; ++i) {
      provinces.insert(find(i));
    }
    return provinces.size();
  }

 private:
  void merge(int i, int j) {
    int x = find(i);
    int y = find(j);
    parents[y] = x;
  }

  int find(int i) {
    return parents[i] == i
        ? i
        : parents[i] = find(parents[i]);
  }

  int n;
  vector<int> parents;
};

// Method 2: BFS
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    unordered_set<int> unvisited;
    for (int i = 0; i < n; ++i) {
      unvisited.insert(i);
    }
    int result = 0;
    while (!unvisited.empty()) {
      ++result;
      queue<int> q;
      q.push(*unvisited.begin());
      unvisited.erase(unvisited.begin());
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v) {
          if (isConnected[u][v] && unvisited.contains(v)) {
            q.push(v);
            unvisited.erase(v);
          }
        }
      }
    }
    return result;
  }
};

// 2017-04-22
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
