// Copyright 2017 Qi Wang
// Date: 2017-05-13
#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
 
using namespace std;
 
int h, w, d, r;
vector<vector<char>> board;
vector<vector<bool>> visited;
bool wrap = false;
int result = INT_MAX;
 
inline bool Invalid(int x, int y) {
  return x < 1 || x > h || y < 1 || y > w;
}
 
inline bool Black(int x, int y) {
  return board[x][y] == '#';
}
 
inline bool cannotGo(int x, int y) {
  return Invalid(x, y) || Black(x, y) || visited[x][y];
}
 
void Dfs(int i, int j, int move) {
  if (move >= result) return;
  // cout << i << ", " << j << endl;
  if (i == h && j == w) {
    result = min(result, move);
    return;
  }
  visited[i][j] = true;
  static int dir[] = {1, 0, -1, 0, 1};
  for (int k = 0; k < 4; ++k) {
    int x = i + dir[k], y = j + dir[k + 1];
    if (cannotGo(x, y)) continue;
    Dfs(x, y, move + 1);
  }
  int x = i + d, y = j + r;
  if (!wrap && !cannotGo(x, y)) {
    wrap = true;
    Dfs(x, y, move + 1);
    wrap = false;
  }
  visited[i][j] = false;
}
 
int main() {
  cin >> h >> w >> d >> r;
  board = vector<vector<char>>(h + 1, vector<char>(w + 1));
  visited = vector<vector<bool>>(h + 1, vector<bool>(w + 1, false));
  for (int i = 0; i < h; ++i)
      // cin >> board[i + 1][j + 1];
      scanf("%s", board[i + 1].data() + 1);
  Dfs(1, 1, 0);
  cout << (result == INT_MAX ? -1 : result) << endl;
}