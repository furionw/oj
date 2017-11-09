// Copyright 2017 Qi Wang
// Date: 2017-11-08
class RandomizedSet {
 public:
  bool insert(int val) {
    if (num_to_idx_map_.count(val) == 0) {
      num_to_idx_map_[val] = nums_.size();
      nums_.push_back(val);
      return true;
    } else {
      return false;
    }
  }
 
  bool remove(int val) {
    if (num_to_idx_map_.count(val)) {
      int remove_idx = num_to_idx_map_[val];
      int back_val = nums_.back();
      nums_[remove_idx] = back_val;
      num_to_idx_map_[back_val] = remove_idx;
      num_to_idx_map_.erase(val);
      nums_.pop_back();
      return true;
    } else {
      return false;
    }
  }
 
  int getRandom() {
    if (nums_.empty()) return INT_MIN;
    return nums_[rand() % nums_.size()];
  }
 
 private:
  vector<int> nums_;
  unordered_map<int, int> num_to_idx_map_;
};

// Date: 2017-08-16
class RandomizedSet {
 public:
  bool insert(int val) {
    if (num_to_idx_map.find(val) != num_to_idx_map.end()) {
      return false;
    } else {
      num_to_idx_map[val] = nums_.size();
      nums_.push_back(val);
      return true;
    }
  }
    
  bool remove(int val) {
    if (num_to_idx_map.find(val) == num_to_idx_map.end()) {
      return false;
    } else {
      num_to_idx_map[nums_.back()] = num_to_idx_map[val];
      swap(nums_.back(), nums_[num_to_idx_map[val]]);
      nums_.pop_back();
      num_to_idx_map.erase(val);
      return true;
    }
  }
    
  int getRandom() {
    return !nums_.empty() ? nums_[rand() % nums_.size()] : INT_MIN;
  }
 
 private:
  unordered_map<int, int> num_to_idx_map;
  vector<int> nums_;
};

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
