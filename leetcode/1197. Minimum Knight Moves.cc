// 2025-07-25
// Method 3: refer to the Editorial. memorization + DFS
class Solution {
 public:
  int minKnightMoves(int x, int y) {
    return dfs(abs(x), abs(y));
  }

 private:
  unordered_map<int, int> dist;

  int dfs(int x, int y) {
    if (x == 0 && y == 0) {
      return 0;
    } else if (x + y == 2) {
      return 2;
    }

    int u = idx(x, y);
    if (dist.contains(u)) {
      return dist[u];
    }

    return dist[u] = min(
        dfs(abs(x - 2), abs(y - 1)),
        dfs(abs(x - 1), abs(y - 2))) + 1;
  }

  int idx(int x, int y) {
    return x * 1e4 + y;
  }
};

// Method 2: just a queue
class Solution {
 public:
  int minKnightMoves(int x, int y) {
    unordered_set<int> visited {0};
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    for (int cnt = 0; true; ++cnt) {
      queue<pair<int, int>> next;
      while (!q.empty()) {
        auto [px, py] = q.front();
        q.pop();
        if (px == x && py == y) {
          return cnt;
        }
        static vector<vector<int>> deltas {
          {2, 1},
          {2, -1},
          {1, 2},
          {1, -2},
          {-2, 1},
          {-2, -1},
          {-1, 2},
          {-1, -2}
        };
        for (const auto& d : deltas) {
          int i = px + d[0];
          int j = py + d[1];
          // if (!visited[idx(i].contains(j)) {
          if (!visited.contains(idx(i, j))) {
            next.emplace(i, j);
            // visited[i].insert(j);
            visited.insert(idx(i, j));
          }
        }
      }
      q = move(next);
    }
    return -1;
  }
  
 private:
  int idx(int x, int y) {
    return x * 1e3 + y;
  }
};

// 2025-07-25
// Method 1: pq
struct Point {
  int cnt;
  int x;
  int y;

  bool operator<(const Point& other) const {
    return cnt != other.cnt
        ? cnt > other.cnt
        : (x != other.x ? x < other.x : y < other.y);
  }
};

class Solution {
 public:
  int minKnightMoves(int x, int y) {
    unordered_map<int, unordered_set<int>> visited;
    priority_queue<Point, vector<Point>> pq;
    pq.push(Point {.cnt = 0, .x = 0, .y = 0});
    visited[0].insert(0);
    while (true) {
      auto p = pq.top();
      pq.pop();
      if (p.x == x && p.y == y) {
        return p.cnt;
      }
      static vector<vector<int>> deltas {
        {2, 1},
        {2, -1},
        {1, 2},
        {1, -2},
        {-2, 1},
        {-2, -1},
        {-1, 2},
        {-1, -2}
      };
      for (const auto& d : deltas) {
        int i = p.x + d[0];
        int j = p.y + d[1];
        if (!visited[i].contains(j)) {
          pq.push(Point {.cnt = p.cnt + 1, .x = i, .y = j});
          visited[i].insert(j);
        }
      }
    }
    return -1;
  }
  
 private:
  int idx(int x, int y) {
    return x * 1e3 + y;
  }
};
