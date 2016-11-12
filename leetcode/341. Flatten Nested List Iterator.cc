// Copyright 2016 Qi Wang
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
