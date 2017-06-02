// Copyright 2017 Qi Wang
// Date: 2017-06-02
class Solution {
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> result(length, 0), record(length + 1, 0);
    for (const auto& update : updates) {
      record[update[0]] += update[2];
      record[update[1] + 1] -= update[2];
    }
    int inc = 0;
    for (int i = 0; i < length; ++i)
      result[i] = inc += record[i];
    return result;
  }
};
