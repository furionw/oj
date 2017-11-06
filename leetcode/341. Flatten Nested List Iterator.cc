// Copyright 2017 Qi Wang
// Date: 2017-11-06
class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList)
      : nested_integers_(nestedList.begin(), nestedList.end()) {}

  int next() {
    int result = nested_integers_.front().getInteger();
    nested_integers_.pop_front();
    return result;
  }
 
  bool hasNext() {
    while (!nested_integers_.empty() &&
           !nested_integers_.front().isInteger()) {
      auto front = nested_integers_.front().getList();
      nested_integers_.pop_front();
      for (auto itr = front.rbegin(); itr != front.rend(); ++itr) {
        nested_integers_.push_front(*itr);
      }
    }
    return !nested_integers_.empty();
  }
 
 private:
  list<NestedInteger> nested_integers_;
};

// Date: 2017-07-24
class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    nested_integers_ = list<NestedInteger>(
        nestedList.begin(), nestedList.end());
  }

  int next() {
    int result = nested_integers_.front().getInteger();
    nested_integers_.pop_front();
    return result;
  }

  bool hasNext() {
    while (!nested_integers_.empty() &&
        !nested_integers_.front().isInteger()) {
      auto nested_integers = nested_integers_.front().getList();
      nested_integers_.pop_front();
      for (auto itr = nested_integers.rbegin();
          itr != nested_integers.rend(); ++itr) {
        nested_integers_.push_front(*itr);
      }
    }
    return !nested_integers_.empty();
  }

 private:
  list<NestedInteger> nested_integers_;
};

// Date: 2017-01-04
class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    pushFromBack(nestedList);
  }

  int next() {
    int res = stk_.top().getInteger();
    stk_.pop();
    return res;
  }

  bool hasNext() {
    makeTopInteger();
    return !stk_.empty();
  }

 private:
  void makeTopInteger() {
    while (!stk_.empty() && !stk_.top().isInteger()) {
      auto nestedList = stk_.top().getList();
      stk_.pop();
      pushFromBack(nestedList);
    }
  }

  void pushFromBack(const vector<NestedInteger> &nestedList) {
    if (nestedList.empty()) return;
    for (int i = nestedList.size() - 1; i >= 0; --i)
      stk_.push(nestedList[i]);
  }

  stack<NestedInteger> stk_;
};

// Date: 2016-11-12
class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList)
      : nums_(parseList(nestedList)), it_(nums_.begin()) {}

  inline int next() { return *(it_++); }

  inline bool hasNext() { return it_ != nums_.end(); }

 private:
  inline list<int> parseList(const vector<NestedInteger> &nestedList) const {
    list<int> res;
    for (const auto& elem : nestedList) {
      if (elem.isInteger()) {
        res.push_back(elem.getInteger());
      } else {
        res.splice(res.end(), parseList(elem.getList()));
      }
    }
    return res;
  }

  list<int> nums_;
  list<int>::iterator it_;
};
