// Copyright 2016 Qi Wang
// Date: 2016-11-11
class SummaryRanges {
 public:
  /** Initialize your data structure here. */
  SummaryRanges() {
  
  }
    
  void addNum(int val) {
    if (intervals_.empty()) {
      intervals_.emplace_back(val, val);
      return;
    } else if (val < intervals_.front().start) {
      if (val + 1 == intervals_.front().start) {
        --intervals_.front().start;
      } else {
        intervals_.insert(intervals_.begin(), Interval(val, val));
      }
      return;
    }
    size_t i = 0;
    for (; i < intervals_.size() && val > intervals_[i].end; ++i) {}
    if (i == intervals_.size()) {
      if (intervals_.back().end + 1 == val) {
        ++intervals_.back().end;
      } else {
        intervals_.emplace_back(val, val);
      }
      return;
    } else if (intervals_[i].start <= val && val <= intervals_[i].end) {
      return;
    } else {
      if (intervals_[i - 1].end + 1 == val && val + 1 == intervals_[i].start) {
        intervals_[i - 1].end = intervals_[i].end;
        intervals_.erase(intervals_.begin() + i);
      } else if (intervals_[i - 1].end + 1 == val) {
        ++intervals_[i - 1].end;
      } else if (val + 1 == intervals_[i].start) {
        --intervals_[i].start;
      } else {
        intervals_.insert(intervals_.begin() + i, Interval(val, val));
      }
    }
  }
    
  vector<Interval> getIntervals() {
    return intervals_;
  }

 private:
  vector<Interval> intervals_;
};
