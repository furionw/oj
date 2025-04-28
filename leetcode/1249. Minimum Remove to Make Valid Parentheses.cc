// 2025-04-27
class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    unordered_set<int> idxsToRemove;
    int balance = 0;

    for (int i = 0; i < s.size(); ++i) {
      const char c = s[i];
      if (c == '(') {
        ++balance;
      } else if (c == ')') {
        if (balance == 0) {
          idxsToRemove.insert(i);
        } else {
          --balance;
        }
      }
    }

    for (int i = s.size() - 1; balance > 0 && i >= 0; --i) {
      if (s[i] == '(') {
        idxsToRemove.insert(i);
        --balance;
      }
    }

    string result(s.size() - idxsToRemove.size(), 0 /*ch*/);
    for (int i = 0, j = 0; i < result.size(); ++i, ++j) {
      for (; idxsToRemove.contains(j); ++j) {}
      result[i] = s[j];
    }

    return result;
  }
};

// 1 <= s.length <= 10^5

// case 1: s == )
// iter 1: i = 0
//   idxsToRemove = {0}
// result = ""

// case 2: s == (
// iter 1: i = 0
//   balance = 1
// iter 1: i = 0
//   idxsToRemove = {0}
//   balance = 0
// result = ""

// case 3: s = (n)x
// iter 1: i = 0
//   balance = 1
// ...
// iter 3: i = 2
//   balance = 0
// ...