// Copyright 2016 Qi Wang
// Date: 2016-11-30
class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (idxMap_.find(val) == idxMap_.end()) {
      nums_.push_back(val);
      idxMap_[val] = nums_.size() - 1;
      return true;
    } else {
      return false;
    }
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if (idxMap_.find(val) != idxMap_.end()) {
      int back = nums_.back();
      swap(nums_[idxMap_[val]], nums_.back());
      idxMap_[back] = idxMap_[val];
      idxMap_.erase(val);
      nums_.pop_back();
      return true;
    } else {
      return false;
    }
  }

  /** Get a random element from the set. */
  int getRandom() {
    return nums_[rand() % nums_.size()];
  }

 private:
  vector<int> nums_;
  unordered_map<int, int> idxMap_;
};
