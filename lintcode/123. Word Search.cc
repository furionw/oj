// Copyright 2017 Qi Wang
// Date: 2017-10-11
class Solution {
 public:
  bool exist(vector<vector<char>> &board, string &word) {
    if (word.empty()) return true;
    if (board.empty()) return false;
    vector<vector<bool>> vi(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == word[0] && Exist(board, i, j, word, 1, &vi)) {
          return true;
        }
      }
    }
    return false;
  }
 
 private:
  bool Exist(const vector<vector<char>>& board, int x, int y,
             const string& word, int idx, vector<vector<bool>>* vi) const {
    if (idx == word.size()) return true;
    (*vi)[x][y] = true;
    static constexpr int delta[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d) {
      int i = x + delta[d], j = y + delta[d + 1];
      if (0 <= i && i < board.size() && 0 <= j && j < board[0].size() &&
          !(*vi)[i][j] && board[i][j] == word[idx]) {
        if (Exist(board, i, j, word, idx + 1, vi)) return true;
      }
    }
    (*vi)[x][y] = false;
    return false;
  }
};
