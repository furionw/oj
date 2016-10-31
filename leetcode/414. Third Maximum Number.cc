// Copyright 2016 Qi Wang
// Date: 2016-10-30
class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    set<int> s;
    for (int num : nums) {
      s.insert(num);
      if (s.size() > 3) s.erase(s.begin());
    }
    return s.size() == 3 ? *s.begin() : *s.rbegin();
  }
};
