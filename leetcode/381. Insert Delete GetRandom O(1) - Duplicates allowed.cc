// Copyright 2016 Qi Wang
// Date: 2016-11-30
class RandomizedCollection {
 public:
  /** Initialize your data structure here. */
  RandomizedCollection() {}

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    idxTbl_[val].push_back(vals_.size());
    vals_.push_back(val);
    its_.push_back(--idxTbl_[val].end());
    return idxTbl_[val].size() == 1;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if (idxTbl_.find(val) != idxTbl_.end()) {
      int rmIdx = idxTbl_[val].back();
      swap(vals_[rmIdx], vals_.back());
      vals_.pop_back();
      swap(its_[rmIdx], its_.back());
      *its_[rmIdx] = rmIdx;
      // pop_back should be executed after *its_[rmIdx] = rmIdx, 'cause rmIdx
      // might point to the back of its_
      its_.pop_back();
      idxTbl_[val].pop_back();
      if (idxTbl_[val].empty()) idxTbl_.erase(val);
      return true;
    } else {
      return false;
    }
  }

  /** Get a random element from the set. */
  int getRandom() {
    return vals_[rand() % vals_.size()];
  }

 private:
  vector<int> vals_;
  vector<list<int>::iterator> its_;
  unordered_map<int, list<int>> idxTbl_;
};
