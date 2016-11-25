// Copyright 2016 Qi Wang
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
