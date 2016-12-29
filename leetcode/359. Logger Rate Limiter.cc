// Copyright 2016 Qi Wang
// Date: 2016-12-29
class Logger {
 public: 
  bool shouldPrintMessage(int timestamp, string msg) {
    if (record_.count(msg) == 0 || timestamp - record_[msg] >= 10) {
      record_[msg] = timestamp;
      return true;
    }
    return false;
  }

 private:
  unordered_map<string, int> record_;
};
