// Copyright 2017 Qi Wang
// Date: 2017-06-11
class StringIterator {
 public:
  StringIterator(string compressedString)
      : str_(compressedString),
        p_(str_.data()) {
    if (!compressedString.empty()) {
      auto q = p_ + 1;
      while (isdigit(*q))
        cnt_ = cnt_ * 10 + *(q++) - '0';
    }
  }
  
  char next() {
    if (!hasNext()) return ' ';
    char result = *p_;
    if (0 == --cnt_) advance();
    return result;
  }
  
  bool hasNext() {
    return cnt_ > 0 && 0 != *p_;
  }

 private:
  void advance() {
    while (isdigit(*(++p_))) {}
    if (0 == *p_) return;
    auto q = p_ + 1;
    while (isdigit(*q))
      cnt_ = cnt_ * 10 + *(q++) - '0';
  }

  int cnt_ = 0;
  string str_;
  const char* p_;
};
