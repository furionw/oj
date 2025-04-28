// 2025-04-27
class Logger {
 public:
  Logger() {}
    
  bool shouldPrintMessage(int timestamp, string message) {
    if (!lastPrinted_.contains(message)
      || lastPrinted_[message] + 10 <= timestamp
    ) {
      lastPrinted_[message] = timestamp;
      return true;
    } else {
      return false;
    }
  }

 private:
  std::unordered_map<string, int> lastPrinted_;
};


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
