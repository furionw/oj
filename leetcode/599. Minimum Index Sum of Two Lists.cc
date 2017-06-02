// Copyright 2017 Qi Wang
// Date: 2017-06-02
class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1,
      vector<string>& list2) {
    unordered_map<string, int> idx;
    for (const auto& elem : list1) idx[elem] = idx.size();
    int sum = INT_MAX;
    vector<string> result;
    for (int i = 0; i < list2.size(); ++i) {
      if (idx.count(list2[i]) == 0) continue;
      int cur = i + idx[list2[i]];
      if (cur < sum) {
        result = vector<string>(1, list2[i]);
        sum = cur;
      } else if (cur == sum) {
        result.push_back(list2[i]);
      }
    }
    return result;
  }
};
