// Copyright 2016 Qi Wang
// Date: 2016-10-06
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    auto cnts1 = count(nums1);
    auto cnts2 = count(nums2);
    vector<int> res;
    for (auto cnt : cnts1) {
      int times = min(cnt.second, cnts2[cnt.first]);
      for (int i = 0; i < times; ++i) res.push_back(cnt.first);
    }
    return res;
  }

 private:
  inline unordered_map<int, int> count(const vector<int>& nums) const {
    unordered_map<int, int> cnts;
    for (int num : nums) ++cnts[num];
    return cnts;
  }
};
