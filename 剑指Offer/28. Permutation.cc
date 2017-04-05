// Copyright 2017 Qi Wang
// Date: 2017-04-04
// It's similar to the LC 31. Next Permutation
class Solution {
 public:
  vector<string> Permutation(string str) {
    if (str.empty()) return vector<string>();
    sort(str.begin(), str.end());
    vector<string> result;
    do {
      result.push_back(str);
    } while(next_permutation(str.begin(), str.end()));
    return result;
  }
};
