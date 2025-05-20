// 2025-05-19
class HitCounter {
 public:
  void hit(int timestamp) {
    hits.push_back(timestamp);
  }
  
  int getHits(int timestamp) {
    while (!hits.empty() && hits.front() <= timestamp - 300) {
      hits.pop_front();
    }
    return hits.size();
  }

 private:
  list<int> hits;
};

// Follow up: What if the number of hits per second could be huge? Does your design scale?
// Answer: refactor `hits` as `map<int, int> timestampToHits`

// 2017-09-08
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

