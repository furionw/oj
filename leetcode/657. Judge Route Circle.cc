// Copyright 2017 Qi Wang
// Date: 2017-09-13
class Solution {
 public:
  bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (char c : moves) {
      if (c == 'U') {
        ++x;
      } else if (c == 'D') {
        --x;
      } else if (c == 'L') {
        --y;
      } else if (c == 'R') {
        ++y;
      } else {
        return false;  // illegal input
      }
    }
    return x == 0 && y == 0;
  }
};

// Date: 2017-08-12
// Method 2
class Solution {
 public:
  bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (char c : moves) {
      if (c == 'R') {
        ++y;
      } else if (c == 'L') {
        --y;
      } else if (c == 'U') {
        ++x;
      } else {
        --x;
      }
    }
    return x == 0 && y == 0;
  }
};

// Date: 2017-08-12
// Method 1
class Solution {
 public:
  bool judgeCircle(string moves) {
    int dir[] = {0, 1, 0, -1, 0};
    unordered_map<char, int> m {
      {'R', 0},
      {'D', 1},
      {'L', 2},
      {'U', 3}
    };
    int x = 0, y = 0;
    for (char c : moves) {
      x += dir[m[c]];
      y += dir[m[c] + 1];
    }
    return x == 0 && y == 0;
  }
};