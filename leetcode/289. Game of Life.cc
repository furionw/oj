// Copyright 2017 Qi Wang
// Date: 2017-01-01
class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    if (board.empty() || board[0].empty()) return;
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[0].size(); ++j) {
        int cnt = countLiveCell(board, i, j);
        if ((board[i][j] & 1 && (cnt == 2 || cnt == 3))  // live cell
            || (!(board[i][j] & 1) && cnt == 3))  // dead cell
          board[i][j] |= 2;
      }
    for (auto& row : board)
      for (auto& cell : row)
        cell >>= 1;
  }

 private:
  int countLiveCell(vector<vector<int>>& board, int x, int y) const {
    static constexpr int DELTA[] = {-1, 0, 1};
    int cnt = 0;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j) {
        if (i == 1 && j == 1) continue;
        int new_x = x + DELTA[i], new_y = y + DELTA[j];
        if (0 <= new_x && new_x < board.size() && 0 <= new_y
            && new_y < board[0].size() && board [new_x][new_y] & 1)
          ++cnt;
      }
    return cnt;
  }
};

// Date: 2016-11-25
class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[0].size(); ++j) {
        int liveCnt = 0;
        if (legal(board, i - 1, j - 1)) liveCnt += board[i - 1][j - 1] & 1;
        if (legal(board, i - 1, j))     liveCnt += board[i - 1][j] & 1;
        if (legal(board, i - 1, j + 1)) liveCnt += board[i - 1][j + 1] & 1;
        if (legal(board, i, j - 1))     liveCnt += board[i][j - 1] & 1;
        if (legal(board, i, j + 1))     liveCnt += board[i][j + 1] & 1;
        if (legal(board, i + 1, j - 1)) liveCnt += board[i + 1][j - 1] & 1;
        if (legal(board, i + 1, j))     liveCnt += board[i + 1][j] & 1;
        if (legal(board, i + 1, j + 1)) liveCnt += board[i + 1][j + 1] & 1;
        if ((board[i][j] && (liveCnt == 2 || liveCnt == 3))
            || (!board[i][j] && liveCnt == 3)) board[i][j] |= 2;
      }
    for (auto& row : board)
      for (auto& cell : row)
        cell >>= 1;
  }

 private:
  inline bool legal(const vector<vector<int>>& board, int i, int j) const {
    return 0 <= i && i <= board.size() - 1
        && 0 <= j && j <= board[0].size() - 1;
  }
};
