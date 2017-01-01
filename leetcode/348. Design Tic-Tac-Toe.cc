// Copyright 2016 Qi Wang
// Date: 2016-12-31
// Method 2
class TicTacToe {
 public:
  TicTacToe(int n)
      : rows_(vector<int>(n, 0)), cols_(vector<int>(n, 0)),
        diagonal_(0), antiDiag_(0) {}
    
  int move(int row, int col, int player) {
    // increment or decrement operation
    auto op = [player](int& cnt) { return cnt += player == 1 ? 1 : -1; };
    int cnt = rows_.size() * (player == 1 ? 1 : -1);
    if (op(rows_[row]) == cnt || op(cols_[col]) == cnt
        || (row == col && op(diagonal_) == cnt)
        || (row + col == rows_.size() - 1 && op(antiDiag_) == cnt))
      return player;
    return 0;
  }

 private:
  vector<int> rows_;
  vector<int> cols_;
  int diagonal_, antiDiag_;
};

// Date: 2016-12-31
// Method 1
class TicTacToe {
 public:
  TicTacToe(int n) : board_(vector<vector<int>>(n, vector<int>(n, 0))) {}
    
  int move(int row, int col, int player) {
    board_[row][col] = player;

    // horizontal
    if (all_of(board_[row].begin(), board_[row].end(), [player](int chess) {
      return chess == player;
    })) return player;

    // vertical
    bool allPlayer = true;
    for (size_t i = 0; i < board_.size() && allPlayer; ++i)
        allPlayer = board_[i][col] == player;
    if (allPlayer) return player;

    // diagonal (top-left to bottom-right)
    if (col == row) {
      allPlayer = true;
      for (size_t i = 0; i < board_.size() && allPlayer; ++i)
        allPlayer = board_[i][i] == player;
      if (allPlayer) return player;
    }

    // diagonal (top-right to bottom-left)
    if (col + row == board_.size() - 1) {
      allPlayer = true;
      for (size_t i = 0; i < board_.size() && allPlayer; ++i)
        allPlayer = board_[i][board_.size() - 1 - i] == player;
      if (allPlayer) return player;
    }

    return 0;
  }

 private:
  vector<vector<int>> board_;
};
