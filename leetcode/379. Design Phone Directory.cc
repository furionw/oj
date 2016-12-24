// Copyright 2016 Qi Wang
// Date: 2016-12-23
// Method 2: refer to one of the top solution
class PhoneDirectory {
 public:
  PhoneDirectory(int maxNumbers)
      : freeNums_(vector<int>(maxNumbers)),
        isFree_(vector<bool>(maxNumbers, true)) {
    for (int i = 0; i < maxNumbers; ++i) freeNums_[i] = i;
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (idx_ < freeNums_.size()) {
      int res = freeNums_[idx_++];
      isFree_[res] = false;
      return res;
    } else {
      return -1;
    }
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    return 0 <= number && number < isFree_.size() ? isFree_[number] : false;
  }

  /** Recycle or release a number. */
  void release(int number) {
    if (number < 0 || number >= isFree_.size() || isFree_[number]) return;
    freeNums_[--idx_] = number;
    isFree_[number] = true;
  }

 private:
  int idx_ = 0;
  vector<int> freeNums_;
  vector<bool> isFree_;
};

// Date: 2016-12-23
// Method 1
class PhoneDirectory {
 public:
  PhoneDirectory(int maxNumbers)
      : MAX_(maxNumbers - 1), givenPool_(vector<bool>(maxNumbers, false)) {}

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (curMax_ < MAX_) {
      givenPool_[++curMax_] = true;
      return curMax_;
    } else if (!reservedPool_.empty()) {
      int res = reservedPool_.front();
      givenPool_[res] = true;
      reservedPool_.pop_front();
      return res;
    } else {
      return -1;
    }
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    // return number <= MAX_ && !givenPool_[number];
    return !givenPool_[number];
  }

  /** Recycle or release a number. */
  void release(int number) {
    // if (number <= MAX_ && givenPool_[number]) {
    if (givenPool_[number]) {
      givenPool_[number] = false;
      reservedPool_.push_back(number);
    }
  }

 private:
  vector<bool> givenPool_;
  list<int> reservedPool_;
  const int MAX_;
  int curMax_ = -1;
};
