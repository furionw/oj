// Copyright 2017 Qi Wang
// Date: 2017-04-06
class Solution {
 public:
  string PrintMinNumber(vector<int> numbers) {
    vector<string> strs;
    for (int num : numbers) strs.push_back(to_string(num));
    sort(strs.begin(), strs.end(), [](const string& lhs, const string& rhs) {
      return (lhs + rhs) < (rhs + lhs);
    });
    return accumulate(strs.begin(), strs.end(), string(),
        [](const string& acc, const string& cur) {
          return acc + cur;
        });
  }
};
