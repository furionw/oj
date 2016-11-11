// Copyright 2016 Qi Wang
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
