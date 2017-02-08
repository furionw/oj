// Copyright 2017 Qi Wang
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
