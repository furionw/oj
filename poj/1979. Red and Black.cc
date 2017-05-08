// Copyright 2017 Qi Wang
// Date: 2017-05-08
#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<char> >& board, int x, int y, int& result) {
  if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()
      || board[x][y] == '#')
    return;
  ++result;
  board[x][y] = '#';
  static int dir[] = {1, 0, -1, 0, 1};
  for (int d = 0; d < 4; ++d)
    solve(board, x + dir[d], y + dir[d + 1], result);
}

int main() {
  for (int w, h; cin >> w >> h, w != 0 && h != 0;) {
    vector<vector<char> > board(h, vector<char>(w));
    int x, y;
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j) {
        cin >> board[i][j];
        if (board[i][j] == '@') x = i, y = j;
      }
    int result = 0;
    solve(board, x, y, result);
    cout << result << endl;
  }
}
