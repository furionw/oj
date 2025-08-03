// 2025-07-28
class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    unordered_set<int> visited;
    queue<int> q;
    int kEnd = 123450;
    q.push(idx(board));
    visited.insert(q.front());

    if (q.front() == kEnd) {
      return 0;
    }

    for (int cnt = 1; !q.empty(); ++cnt) {
      queue<int> next;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        fill(u, board);
        for (int v : neighbors(board)) {
          if (v == kEnd) {
            return cnt;
          } else if (!visited.contains(v)) {
            next.push(v);
            visited.insert(v);
          }
        }
      }
      q = move(next);
    }

    return -1;
  }

 private:
  int idx(const vector<vector<int>>& board) const {
    return 1e5 * board[0][0] + 1e4 * board[0][1] + 1e3 * board[0][2]
        + 1e2 * board[1][0] + 10 * board[1][1] + board[1][2];
  }

  void fill(int idx, vector<vector<int>>& board) const {
    board[0][0] = idx / 1e5;
    board[0][1] = idx % 100000 / 1e4;
    board[0][2] = idx % 10000 / 1e3;
    board[1][0] = idx % 1000 / 1e2;
    board[1][1] = idx % 100 / 1e1;
    board[1][2] = idx % 10;
  }

  vector<int> neighbors(vector<vector<int>>& board) const {
    int x = -1;
    int y = -1;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (board[i][j] == 0) {
          x = i;
          y = j;
        }
      }
    }
    vector<int> result;
    static vector<int> d {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int x2 = x + d[i];
      int y2 = y + d[i + 1];
      if (x2 < 0 || x2 >= 2 || y2 < 0 || y2 >= 3) {
        continue;
      }
      swap(board[x][y], board[x2][y2]);
      result.push_back(idx(board));
      swap(board[x][y], board[x2][y2]);
    }
    return result;
  }
};
