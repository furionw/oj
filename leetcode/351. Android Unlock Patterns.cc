// Copyright 2016 Qi Wang
// Date: 2016-12-27
// Method 2
class Solution {
 public:
  Solution() {
    memset(pass, 0, sizeof pass);
    pass[1][9] = pass[2][8] = pass[3][7] = pass[6][4] = pass[9][1] = pass[8][2]
        = pass[7][3] = pass[4][6] = 5;
    pass[1][3] = pass[3][1] = 2;
    pass[3][9] = pass[9][3] = 6;
    pass[7][9] = pass[9][7] = 8;
    pass[1][7] = pass[7][1] = 4;
  }

  int numberOfPatterns(int m, int n) {
    bitset<10> vi;
    vi[0] = true;
    int res = 0;
    for (int depth = m; depth <= n; ++depth) {
      res += f(1, depth, vi) << 2;  // refer to the Top Solutions
      res += f(2, depth, vi) << 2;
      res += f(5, depth, vi);
    }
    return res;
  }

 private:
  int f(int u, int depth, bitset<10>& vi) {
    if (depth == 1) return 1;
    int res = 0;
    vi[u] = true;
    for (int v = 1; v <= 9; ++v)
      if (u != v && !vi[v] && vi[pass[u][v]])
        res += f(v, depth - 1, vi);
    vi[u] = false;
    return res;
  }

  // Here I use 2-d array, instead of the map
  int pass[10][10];
};

// Date: 2016-12-27
// Method 1
class Solution {
 public:
  int numberOfPatterns(int m, int n) {
    bitset<10> vi;
    vi[0] = true;
    int res = 0;
    for (int depth = m; depth <= n; ++depth)
      for (int num = 1; num <= 9; ++num)
        res += f(num, depth, vi);
    return res;
  }

 private:
  int f(int u, int depth, bitset<10>& vi) {
    if (depth == 1) return 1;
    int res = 0;
    vi[u] = true;
    for (int v = 1; v <= 9; ++v)
      if (u != v && !vi[v] && vi[pass[make_pair(u, v)]])
        res += f(v, depth - 1, vi);
    vi[u] = false;
    return res;
  }

  map<pair<int, int>, int> pass {
    // start from 1
    {make_pair(1, 3), 2}, {make_pair(1, 7), 4}, {make_pair(1, 9), 5},
    // start from 2
    {make_pair(2, 8), 5}, 
    // 3
    {make_pair(3, 1), 2}, {make_pair(3, 9), 6}, {make_pair(3, 7), 5},
    // 4
    {make_pair(4, 6), 5},
    // 6
    {make_pair(6, 4), 5},
    // 7
    {make_pair(7, 1), 4}, {make_pair(7, 3), 5}, {make_pair(7, 9), 8},
    // 8
    {make_pair(8, 2), 5},
    // 9
    {make_pair(9, 1), 5}, {make_pair(9, 3), 6}, {make_pair(9, 7), 8},
  };
};
