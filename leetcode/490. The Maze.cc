// 2025-07-24
class Solution {
 public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    m = maze.size();
    n = maze[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    dx = destination[0];
    dy = destination[1];
    return f(maze, start[0], start[1]);
  }

 private:
  bool f(vector<vector<int>>& maze, int x, int y) {
    if (x == dx && y == dy) {
      return true;
    }

    visited[x][y] = true;

    // Note
    // Refer to the Editorial, this can be implemented more easily by
    // vector<int> dirX{0, 1, 0, -1};
    // vector<int> dirY{-1, 0, 1, 0};

    // up
    {
      int upX = x;
      for (; upX - 1 >= 0 && maze[upX - 1][y] == 0; --upX) {}
      if (!visited[upX][y] && f(maze, upX, y)) {
        return true;
      }
    }

    // down
    {
      int downX = x;
      for (; downX + 1 < m && maze[downX + 1][y] == 0; ++downX) {}
      if (!visited[downX][y] && f(maze, downX, y)) {
        return true;
      }
    }

    // left
    {
      int leftY = y;
      for (; leftY - 1 >= 0 && maze[x][leftY - 1] == 0; --leftY) {}
      if (!visited[x][leftY] && f(maze, x, leftY)) {
        return true;
      }
    }

    // right
    {
      int rightY = y;
      for (; rightY + 1 < n && maze[x][rightY + 1] == 0; ++rightY) {}
      if (!visited[x][rightY] && f(maze, x, rightY)) {
        return true;
      }
    }

    return false;
  }

  int m;
  int n;
  int dx;
  int dy;
  vector<vector<bool>> visited;
};

// Date: 2017-02-06
// Refer to: https://discuss.leetcode.com/topic/77590/simple-c-dfs-solution-using-set-to-mark-the-visited-end-points

// Date: 2017-02-06
// Method 1
class Solution {
 public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
      vector<int>& dest) {
    if (maze.empty() || maze[0].empty()) return false;
    int m = maze.size(), n = maze[0].size();
    if (!(0 <= start[0] && start[0] < m && 0 <= start[1] && start[1] < n
        && 0 <= dest[0] && dest[0] < m && 0 <= dest[1] && dest[1] < n
        && maze[start[0]][start[1]] == 0 && maze[dest[0]][dest[1]] == 0)) {
      cerr << "Illegal input" << endl;
      return false;
    }
    vector<vector<vector<bool>>> vi(m,
        vector<vector<bool>>(n, vector<bool>(4, false)));
    vector<vector<bool>> stop(m, vector<bool>(n, false));
    choose_direction(maze, start[0], start[1], vi, stop);
    return stop[dest[0]][dest[1]];
  }

 private:
  void choose_direction(const vector<vector<int>>& maze,
      int x, int y, vector<vector<vector<bool>>>& vi,
      vector<vector<bool>>& stop) const {
    for (int i = 0; i < 4; ++i)
      if (!vi[x][y][i])
        go(maze, x, y, vi, i, stop);
  }

  void go(const vector<vector<int>>& maze,
      int x, int y, vector<vector<vector<bool>>>& vi, int dir,
      vector<vector<bool>>& stop) const {
    if (maze[x][y] == 1 || vi[x][y][dir]) return;
    vi[x][y][dir] = true;
    static constexpr int DELTA[] = {0, -1, 0, 1, 0};
    int next_x = x + DELTA[dir], next_y = y + DELTA[dir + 1];
    if (0 <= next_x && next_x < maze.size()
        && 0 <= next_y && next_y < maze[0].size()
        && maze[next_x][next_y] == 0) {
      go(maze, next_x, next_y, vi, dir, stop);
    } else {
      stop[x][y] = true;
      choose_direction(maze, x, y, vi, stop);
    }
  }
};
