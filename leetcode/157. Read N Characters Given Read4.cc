// Copyright 2017 Qi Wang
// Date: 2017-11-04
// Case 1: buf, 5. "12345678"
// Please note that the solution on 2017-08-30 is more concise.
class Solution {
 public:
  int read(char *buf, int n) {
    char chars[4];
    int result = 0;
    while (n > 0) {
      int cnt = read4(chars);
      if (cnt == 0) return result;
      int to_cpy = min(cnt, n);
      strncpy(buf, chars, to_cpy);
      buf += to_cpy;
      n -= to_cpy;
      result += to_cpy;
    }
    return result;
  }
};

// Date: 2017-08-30
class Solution {
 public:
  int read(char *buf, int n) {
    char temp[4];
    int i = 0;
    while (i < n) {
      int num = read4(temp);
      strncpy(buf + i, temp, min(n - i, num));
      i += num;
      if (num < 4) break;
    }
    return i <= n ? i : n;
  }
};

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
