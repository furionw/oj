// Copyright 2017 Qi Wang
// Date: 2017-05-13
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  vector<vector<char>> board(h, vector<char>(w));
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      cin >> board[i][j];
  vector<vector<char>> result(a * h, vector<char>(b * w));
  for (int i = 0; i < a * h; ++i)
    for (int j = 0; j < b * w; ++j)
      result[i][j] = board[i % h][j % w];
  for (const auto& row : result) {
    for (char c : row)
      cout << char(c);
    cout << endl;
  }
}