// Copyright 2017 Qi Wang
// Date: 2017-08-15
class Solution {
 public:
  int read(char *buf, int n) {
    int acc = 0;
    while (acc < n) {
      char temp[4];
      int num = read4(temp);
      if (num == 0) break;
      strncpy(buf + acc, temp, num);
      acc += num;
      if (num < 4) break;
    }
    return acc < n ? acc : n;
  }
};

// Date: 2017-07-10
class Solution {
 public:
  int read(char *buf, int n) {
    int result = 0;
    while (true) {
      // Commented on 2017-08-15
      // no safe. Because it might write out of the buf
      int cnt = read4(buf);
      result += cnt;
      buf += cnt;
      if (cnt < 4 || result >= n) {
        break;
      }
    }
    return result >= n ? n : result;
  }
};

// Date: 2017-01-01
class Solution {
 public:
  int read(char *buf, int n) {
    int cnt = 0;
    for (int oldCnt = 0; cnt < n && (cnt += read4(buf + cnt)) > oldCnt;
        oldCnt = cnt) {}
    return cnt < n ? cnt : n;
  }
};
