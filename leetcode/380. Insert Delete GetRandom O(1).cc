// Copyright 2017 Qi Wang
// Date: 2017-07-29
class RandomizedSet {
 public:
  bool insert(int val) {
    if (val_to_idx_map_.find(val) == val_to_idx_map_.end()) {
      val_to_idx_map_[val] = nums_.size();
      nums_.push_back(val);
      return true;
    } else {
      return false;
    }
  }

  bool remove(int val) {
    if (val_to_idx_map_.find(val) == val_to_idx_map_.end()
        || nums_.empty()) {
      return false;
    } else {
      // The solution on 2017-01-04 is more concise
      int idx_to_remove = val_to_idx_map_[val];
      val_to_idx_map_[nums_.back()] = idx_to_remove;
      nums_[idx_to_remove] = nums_.back();
      nums_.pop_back();
      val_to_idx_map_.erase(val);
      return true;
    }
  }

  int getRandom() {
    return nums_[rand() % nums_.size()];
  }

 private:
  vector<int> nums_;
  unordered_map<int, int> val_to_idx_map_;;
};

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
