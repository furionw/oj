// Copyright 2017 Qi Wang
// Date: 2017-01-01
class Iterator {
  struct Data;
  Data* data;
 public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  int next();
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {}

  int peek() {
    if (!hasPeeked_) {
      hasPeeked_ = true;
      peekedElem_ = Iterator::next();
    }
    return peekedElem_;
  }

  int next() {
    if (hasPeeked_) {
      hasPeeked_ = false;
      return peekedElem_;
    } else {
      return Iterator::next();
    }
  }

  bool hasNext() const {
    return hasPeeked_ || Iterator::hasNext();
  }

 private:
  // rename variables according to Google's guava library source code
  // https://github.com/google/guava/blob/703ef758b8621cfbab16814f01ddcc5324bdea33/guava-gwt/src-super/com/google/common/collect/super/com/google/common/collect/Iterators.java#L1125
  bool hasPeeked_ = false;
  int peekedElem_;
};

// Date: 2016-12-08
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  struct Data;
  Data* data;
 public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};


class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    if (!elemValid_) {
      elemValid_ = true;
      nextElem_ = Iterator::next();
    }
    return nextElem_;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    if (elemValid_) {
      elemValid_ = false;
      return nextElem_;
    } else {
      return Iterator::next();
    }
  }

  bool hasNext() const {
    return elemValid_ || Iterator::hasNext();
  }

 private:
  bool elemValid_ = false;
  int nextElem_;
};