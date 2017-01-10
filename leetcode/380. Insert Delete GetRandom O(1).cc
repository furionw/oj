// Copyright 2017 Qi Wang
// Date: 2016-11-30
// Last modified: 2017-01-04
class RandomizedSet {
 public:
  bool insert(int val) {
    if (idxMap_.find(val) == idxMap_.end()) {
      nums_.push_back(val);
      idxMap_[val] = nums_.size() - 1;
      return true;
    } else {
      return false;
    }
  }

  bool remove(int val) {
    if (idxMap_.find(val) != idxMap_.end()) {
      idxMap_[nums_.back()] = idxMap_[val];
      swap(nums_[idxMap_[val]], nums_.back());
      idxMap_.erase(val);
      nums_.pop_back();
      return true;
    } else {
      return false;
    }
  }

  int getRandom() {
    return nums_[rand() % nums_.size()];
  }

 private:
  vector<int> nums_;
  unordered_map<int, int> idxMap_;
};
