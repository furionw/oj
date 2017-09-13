// Strategy 1.
// This strategy assumes the opponent will also make the optimal move. Thus the
// result can always be determined once the 'board' is given:
//     - chance == 1. There is an optimal move to win.
//     - chance == 0.5. There is an optimal move to tie.
//     - chance == 0. No matter what moves the player take, he/she will always lose.
// 
// Strategy 2.
// If we assume the opponent will make a move randomly, then the 'Move.chance' could 
// be calculated. I think that's what I missed before. Please note that 
// 'OptimalMoveWhenRandomOpponentMoveRandomly()' is implemented to address this
// problem and the test cases are also provided.
// 
// I guarantee I implemented this code independently and do appreciate the time you
// spent in the interview. Thank you!

#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>

using namespace std;

struct Move {
  int x;
  int y;
  double chance;
};

// Returns if the given 'player' has won in the given 'board'.
inline bool Winner(const vector<vector<char>>& board, char player) {
  // horizontal
  for (const auto& row : board) {
    if (all_of(row.begin(), row.end(), [player](char c) {
      return c == player;
    })) return true;
  }
  int n = board.size();
  // vertical
  for (int j = 0; j < n; ++j) {
    bool all_of = true;
    for (int i = 0; all_of && i < n; ++i) {
      all_of = board[i][j] == player;
    }
    if (all_of) return true;
  }
  // diagonal and anti-diagonal
  bool diagonal = true, anti_diagonal = true;
  for (int i = 0; i < n; ++i) {
    diagonal = diagonal && board[i][i] == player;
    anti_diagonal = anti_diagonal && board[i][n - i - 1] == player; 
  }
  return diagonal || anti_diagonal;
}

// Returns if the given 'board' is full so that no player can take a move anymore.
inline bool Full(vector<vector<char>>& board) {
  for (const auto& row : board) {
    if (any_of(row.begin(), row.end(), [](char c) {
      return c == '.';
    })) return false;
  }
  return true;
}

// Args:
//   board: a valid board not coming out with a winner yet.
//   is_x: if the player use 'x'
Move OptimalMove(vector<vector<char>>& board, bool is_x) {
  if (Full(board)) {
    return {-1, -1, 0.5};
  }
  char player = is_x ? 'x' : 'o';
  double best_chance = 0;
  int best_x = -1, best_y = -1;
  int n = board.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == '.') {
        board[i][j] = player;
        if (Winner(board, player)) {
          board[i][j] = '.';
          return {i, j, 1};
        }
        double temp = 1 - OptimalMove(board, !is_x).chance;
        if (temp > best_chance) {
          best_chance = temp;
          best_x = i;
          best_y = j;
        }
        board[i][j] = '.';
      }
    }
  }
  return {best_x, best_y, best_chance};
}

double OpponentMoveRandomly(vector<vector<char>>& board, bool is_x);

// Args:
//   board: a valid board not coming out with a winner yet.
//   is_x: if the player use 'x'
Move OptimalMoveWhenRandomOpponentMoveRandomly(
    vector<vector<char>>& board, bool is_x) {
  if (Full(board)) {
    return {-1, -1, 0.5};
  }
  char player = is_x ? 'x' : 'o';
  double best_chance = 0;
  int best_x = -1, best_y = -1;
  int n = board.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == '.') {
        board[i][j] = player;
        if (Winner(board, player)) {
          board[i][j] = '.';
          return {i, j, 1};
        }
        double temp = 1 - OpponentMoveRandomly(board, !is_x);
        if (temp > best_chance) {
          best_chance = temp;
          best_x = i;
          best_y = j;
        }
        board[i][j] = '.';
      }
    }
  }
  return {best_x, best_y, best_chance};
}

// Args:
//   board: a valid board not coming out with a winner yet.
//   is_x: if the player use 'x'
// Returns the possibiliy that the opponennt will win this game.
double OpponentMoveRandomly(vector<vector<char>>& board, bool is_x) {
  int choice_cnt = 0;
  double win_acc = 0;
  char player = is_x ? 'x' : 'o';  
  for (auto& row : board) {
    for (char& c : row) {
      if (c == '.') {
        ++choice_cnt;
        c = player;
        if (Winner(board, player)) {
          win_acc += 1;
        } else {
          win_acc += 1 - OptimalMoveWhenRandomOpponentMoveRandomly(
                             board, !is_x).chance;
        }
        c = '.';
      }
    }
  }
  return win_acc / choice_cnt;
}

void Print(const Move& m) {
  cout << m.x << ", " << m.y << ", " << m.chance << endl;
}

int main() {
  // win
  vector<vector<char>> board1 {
    {'x', '.', '.'},
    {'.', 'x', '.'},
    {'.', '.', '.'}
  };
  cout << "Case 1" << endl;
  Print(OptimalMove(board1, /*is_x=*/true));
  Print(OptimalMoveWhenRandomOpponentMoveRandomly(board1, /*is_x=*/true));
  cout << endl;
  
  // tie
  vector<vector<char>> board2 {
    {'o', 'x', '.'},
    {'o', 'o', 'x'},
    {'x', 'o', '.'}
  };
  cout << "Case 2" << endl;
  Print(OptimalMove(board2, /*is_x=*/true));
  Print(OptimalMoveWhenRandomOpponentMoveRandomly(board2, /*is_x=*/true));
  cout << endl;
  
  // tie 2
  vector<vector<char>> board3 {
    {'o', 'x', '.'},
    {'.', 'o', 'x'},
    {'.', 'o', '.'}
  };
  cout << "Case 3" << endl;
  Print(OptimalMove(board3, /*is_x=*/true));
  Print(OptimalMoveWhenRandomOpponentMoveRandomly(board3, /*is_x=*/true));
  cout << endl;
  
  // lose
  vector<vector<char>> board4 {
    {'o', 'x', 'o'},
    {'.', 'o', 'x'},
    {'.', '.', '.'}
  };
  cout << "Case 4" << endl;
  Print(OptimalMove(board4, /*is_x=*/true));
  Print(OptimalMoveWhenRandomOpponentMoveRandomly(board4, /*is_x=*/true));
}
