// Copyright 2017 Qi Wang
// Date: 2017-09-08
class HitCounter {
 public:
  void hit(int timestamp) {
    RemoveInvalidHits(timestamp);
    hits_.push_back(timestamp);
  }

  int getHits(int timestamp) {
    RemoveInvalidHits(timestamp);
    return hits_.size();
  }

 private:
  void RemoveInvalidHits(int timestamp) {
    while (!hits_.empty() && timestamp - hits_.front() >= 300) {
      hits_.pop_front();
    }
  }

  list<int> hits_;
};

