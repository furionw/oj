// Copyright 2017 Qi Wang
// Date: 2017-07-12
// Method 3
// Note that there is also an DFS implementation without multiplication, which uses
// unweighted variable in method 2
// FYI, https://discuss.leetcode.com/topic/49023/share-my-2ms-intuitive-one-pass-no-multiplication-solution 

// Date: 2017-07-12
// Method 2: no DFS, no multiplication
// Refer to: https://discuss.leetcode.com/topic/49041/no-depth-variable-no-multiplication
class Solution {
 public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int unweighted = 0, result = 0;
    while (!nestedList.empty()) {
      vector<NestedInteger> next;
      for (const auto& elem : nestedList) {
        if (elem.isInteger()) {
          unweighted += elem.getInteger();
        } else {
          size_t prev_sz = next.size();
          const auto& children = elem.getList();
          next.resize(prev_sz + children.size());
          copy(children.begin(), children.end(), next.begin() + prev_sz);
        }
      }
      result += unweighted;
      nestedList = move(next);
    }
    return result;
  }
};

// Date: 2017-07-12
// Method 1: DFS
class Solution {
 public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    return DepthSumInverse(nestedList, 1, Depth(nestedList, 1));
  }

 private:
  int DepthSumInverse(const vector<NestedInteger>& nestedList,
                      int cur_depth,
                      int tot_depth) const {
    return accumulate(nestedList.begin(), nestedList.end(), 0,
        [=](int acc, const NestedInteger& cur) {
          return acc + (cur.isInteger()
              ? (tot_depth - cur_depth + 1) * cur.getInteger()
              : DepthSumInverse(cur.getList(), cur_depth + 1, tot_depth)
          );
        });
  }

  int Depth(const vector<NestedInteger>& nestedList, int depth) const {
    int result = depth;
    for (const auto& elem : nestedList) {
      if (!elem.isInteger()) {
        result = max(result, Depth(elem.getList(), depth + 1));
      }
    }
    return result;
  }
};
