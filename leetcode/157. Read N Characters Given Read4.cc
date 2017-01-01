// Copyright 2017 Qi Wang
// Date: 2017-01-01
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
 public:
  int read(char *buf, int n) {
    int cnt = 0;
    for (int oldCnt = 0; cnt < n && (cnt += read4(buf + cnt)) > oldCnt;
        oldCnt = cnt) {}
    return cnt < n ? cnt : n;
  }
};
