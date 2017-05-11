// Copyright 2017 Qi Wang
// Date: 2017-05-11
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 305

struct Cell {
  Cell(int x, int y, int t) : x(x), y(y), time(t) {}
  int x, y, time;
};

bool onceInQ[MAX][MAX];
int board[MAX][MAX];
int bound = 0;
int dir[] = {1, 0, -1, 0, 1};

inline void Update(int i, int j, int k) {
  board[i][j] = -1 == board[i][j] ? k : min(board[i][j], k);
}

inline bool Valid(int x, int y) {
  return 0 <= x && x <= bound && 0 <= y && y <= bound;
}

inline void Spread(int i, int j, int k) {
  for (int d = 0; d < 4; ++d) {
    int x = i + dir[d], y = j + dir[d + 1];
    if (Valid(x, y)) Update(x, y, k);
  }
}

int Bfs() {
  queue<Cell> q;
  q.push(Cell(0, 0, 0));
  onceInQ[0][0] = true;
  while (!q.empty()) {
    Cell pos = q.front();
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int x = pos.x + dir[d], y = pos.y + dir[d + 1];
      if (Valid(x, y) && !onceInQ[x][y]) {
        if (-1 == board[x][y]) return pos.time + 1;
        if (pos.time + 1 < board[x][y]) {
          onceInQ[x][y] = true;
          q.push(Cell(x, y, pos.time + 1));
        }
      }
    }
  }
  return -1;
}

int main() {
  int m;
  cin >> m;
  memset(board, -1, sizeof board);
  for (int i, j, k; m--;) {
    // This is much faster than cin (500ms -> 100ms)
    scanf("%d%d%d", &i, &j, &k);
    // cin >> i >> j >> k;
    bound = max(bound, max(i + 2, j + 2));
    Update(i, j, k);
    Spread(i, j, k);
  }
  cout << (-1 == board[0][0] ? 0 : Bfs()) << endl;
}


// Method 1: TLE. Thus onceInQ is necessary!!!
// Date: 2017-05-11
#include <iostream>
#include <vector>a
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

#define MAX 305

struct Cell {
  Cell(int x, int y, int t) : x(x), y(y), time(t) {}
  int x, y, time;
};

bool visited[MAX][MAX];
int board[MAX][MAX];
int bound = 0;
int dir[] = {1, 0, 1, 0, -1};

inline void Update(int i, int j, int k) {
  board[i][j] = -1 == board[i][j] ? k : min(board[i][j], k);
}

inline bool Valid(int x, int y) {
  return 0 <= x && x <= bound && 0 <= y && y <= bound;
}

inline void Spread(int i, int j, int k) {
  for (int d = 0; d < 4; ++d) {
    int x = i + dir[d], y = j + dir[d + 1];
    if (Valid(x, y)) Update(x, y, k);
  }
}

int Bfs() {
  queue<Cell> q;
  q.push(Cell(0, 0, 0));
  while (!q.empty()) {
    Cell pos = q.front();
    q.pop();
    visited[pos.x][pos.y] = true;
    // safe area
    if (-1 == board[pos.x][pos.y]) {
      return pos.time;
    // arrive before exploding
    } else if (pos.time < board[pos.x][pos.y]) {
      for (int d = 0; d < 4; ++d) {
        int x = pos.x + dir[d], y = pos.y + dir[d + 1];
        if (Valid(x, y) && !visited[x][y]) q.push(Cell(x, y, pos.time + 1));
      }
    }
  }
  return -1;
}

int main() {
  int m;
  cin >> m;
  memset(board, -1, sizeof board);
  for (int i, j, k; m--;) {
    scanf("%d%d%d", &i, &j, &k);
    //cin >> i >> j >> k;
    bound = max(bound, max(i + 2, j + 2));
    Update(i, j, k);
    Spread(i, j, k);
  }
  cout << (-1 == board[0][0] ? 0 : Bfs()) << endl;
}