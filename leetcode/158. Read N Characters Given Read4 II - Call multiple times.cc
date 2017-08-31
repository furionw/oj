// Copyright 2017 Qi Wang
// Date: 2017-08-30
class Solution {
 public:
  int read(char *buf, int n) {
    int result = 0;
    if (len_ != 0) {
      int to_copy = min(len_, n);
      strncpy(buf, storage_, len_);
      result += to_copy;
      if (n < len_) {
        for (int i = 0; i < len_ - n; ++i)
          storage_[i] = storage_[i + n];
        len_ -= n;
      } else {
        len_ = 0;
      }
    }
    while (result < n) {
      char temp[4];
      int sz = read4(temp);
      int remain_to_read = n - result;
      int actual_copy = min(sz, remain_to_read);
      strncpy(buf + result, temp, actual_copy);
      result += actual_copy;
      if (sz > remain_to_read) {
        len_ = sz - remain_to_read;
        strncpy(storage_, temp + remain_to_read, len_);
      } else if (sz < 4) {
        break;
      }
    }
    return result;
  }

 private:
  char storage_[4];
  int len_ = 0;
};


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