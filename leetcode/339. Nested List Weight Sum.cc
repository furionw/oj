// Copyright 2017 Qi Wang
// Date: 2017-07-11
class Solution {
 public:
  int depthSum(vector<NestedInteger>& nestedList) {
    return DepthSum(nestedList, 1);
  }

 private:
  int DepthSum(const vector<NestedInteger>& nestedList, int depth) const {
    return accumulate(
        nestedList.begin(), nestedList.end(), 0,
        [=](int cur, const NestedInteger& elem) {
          return elem.isInteger()
               ? cur + depth * elem.getInteger()
               : cur + DepthSum(elem.getList(), depth + 1);
        });
  }
};
