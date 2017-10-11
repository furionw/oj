#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

struct Path {
  vector<Path> paths;
  int dir;

  Path() {}
  Path(int dir) : dir(dir) {}

  bool operator< (const Path& rhs) const {
    if (dir != rhs.dir) {
      return dir < rhs.dir;
    } else if (paths.size() != rhs.paths.size()) {
      return paths.size() < rhs.paths.size();
    } else {
      for (int i = 0; i < paths.size(); ++i) {
        if (paths[i] < rhs.paths[i]) {
          return true;
        } else if (rhs.paths[i] < paths[i]) {
          return false;
        }
      }
      return false;
    }
  }
};

// Returns the area of the island containing the position (x, y)
int Dfs(vector<string>* board, int x, int y, Path* path) {
  int area = 1;
  (*board)[x][y] = '.';  // marks it as the sea
  static constexpr int delta[5] = {0, 1, 0, -1, 0};
  for (int d = 0; d < 4; ++d) {
    int i = x + delta[d], j = y + delta[d + 1];
    if (i >= 0 && i < board->size() && j >= 0 && j < (*board)[0].size() &&
        (*board)[i][j] == '#') {
      Path sub_path(d);
      area += Dfs(board, i, j, &sub_path);
      path->paths.push_back(sub_path);
    }
  }
  return area;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> board(n, string(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
    }
  }
  int island_cnt = 0;
  unordered_set<int> area_set;
  set<Path> shape_set;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == '#') {
        Path path(-1);
        ++island_cnt;
        area_set.insert(Dfs(&board, i, j, &path));
        shape_set.insert(path);
      }
    }
  }
  cout << island_cnt << " " << area_set.size() << " " << shape_set.size() << endl;
}
