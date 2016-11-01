// Copyright 2016 Qi Wang
// Date: 2016-10-31
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s1, s2;
    for (int num : nums1) s1.insert(num);
    for (int num : nums2) s2.insert(num);
    vector<int> res;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
        back_inserter(res));
    return res;
  }
};
