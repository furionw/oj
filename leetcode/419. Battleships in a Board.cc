// Copyright 2017 Qi Wang
// Date: 2017-07-13
class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return 0;
    int result = 0;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        int x1 = i - 1, y1 = j;
        int x2 = i, y2 = j - 1;
        if ('X' == board[i][j] &&
            (Invalid(x1, y1, board) || 'X' != board[x1][y1]) &&
            (Invalid(x2, y2, board) || 'X' != board[x2][y2])) {
          ++result;
        }
      }
    }
    return result;
  }

 private:
  bool Invalid(int x, int y, const vector<vector<char>>& board) const {
    return x < 0 || x >= board.size() || y < 0 || y >= board[0].size();
  }
};

// Date: 2016-11-10
class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    int res = 0;
    for (size_t i = 0; i < board.size(); ++i)
      for (size_t j = 0; j < board[0].size(); ++j) {
        bool start = board[i][j] == 'X';
        if (start && i != 0 && board[i - 1][j] == 'X') start = false;
        if (start && j != 0 && board[i][j - 1] == 'X') start = false;
        if (start) ++res;
      }
    return res;
  }
};
