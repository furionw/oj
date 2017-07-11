// Copyright 2017 Qi Wang
// Forward declaration of the read4 API.
int read4(char *buf);

// Date: 2017-07-10
class Solution {
 public:
  int read(char *buf, int n) {
    if (str_.size() < n) {
      char s[4];
      int cnt = 0;
      do {
        cnt = read4(s);
        str_ += string(s, cnt);
      } while (cnt > 0 && str_.size() < n);
    }
    int result = str_.size() > n ? n : str_.size();
    strncpy(buf, str_.data(), result);
    str_ = str_.substr(result);
    return result;
  }

 private:
  string str_;
};

// Date: 2017-01-01
class Solution {
 public:
  int read(char *buf, int n) {
    if (n <= reserve_.size()) {
      copy(reserve_.begin(), reserve_.begin() + n, buf);
      reserve_ = reserve_.substr(n);
      return n;
    } else {
      copy(reserve_.begin(), reserve_.end(), buf);
      int cnt = reserve_.size();
      reserve_.clear();
      for (int old_cnt = cnt; cnt < n && (cnt += read4(buf + cnt)) > old_cnt;
          old_cnt = cnt) {}
      if (cnt <= n) {
        return cnt;
      } else {
        reserve_ = string(buf + n, cnt - n);
        cout << reserve_.size() << endl;
        return n;
      }
    }
  }

 private:
  string reserve_;
};