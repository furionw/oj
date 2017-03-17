// Copyright 2017 Qi Wang
// Date: 2017-03-04
class Solution {
 public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board,
      vector<int>& click) {
    int x = click[0], y = click[1];
    // Reveal a mine
    if (board[x][y] == 'M') {
      board[x][y] = 'X';
    // Reveal an empty square
    } else {
      Reveal(board, x, y);
    }
    return board;
  }

 private:
  void Reveal(vector<vector<char>>& board, int x, int y) const {
    int cnt = CountMines(board, x, y);
    if (cnt == 0) {
      board[x][y] = 'B';
      for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
          // Reveal surrounding empty squares recursively
          if (EmptySquare(board, x + i, y + j)) Reveal(board, x + i, y + j);
    } else {
      board[x][y] = cnt + '0';
    }
  }

  int CountMines(const vector<vector<char>>& board, int x, int y) const {
    int cnt = 0;
    for (int i = -1; i <= 1; ++i)
      for (int j = -1; j <= 1; ++j)
        cnt += Mine(board, x + i, y + j);
    return cnt;
  }

  bool EmptySquare(const vector<vector<char>>& board, int x, int y) const {
    return Valid(board, x, y) && board[x][y] == 'E';
  }

  bool Mine(const vector<vector<char>>& board, int x, int y) const {
    return Valid(board, x, y) && board[x][y] == 'M';
  }

  int Valid(const vector<vector<char>>& board, int x, int y) const {
    return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
  }
};
