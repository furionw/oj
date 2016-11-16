// Copyright 2016 Qi Wang
// Date: 2016-11-13
class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
      vector<int>& D) {
    vector<int> nums1, nums2;
    for (int a : A)
      for (int b : B)
        nums1.push_back(a + b);
    for (int c : C)
      for (int d : D)
        nums2.push_back(c + d);
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int res = 0;
    for (int num1 : nums1) {
      // signed greater or equal
      auto GE = lower_bound(nums2.begin(), nums2.end(), -num1);
      // greater
      auto G = upper_bound(nums2.begin(), nums2.end(), -num1);
      res += G - GE;
    }
    return res;
  }
};
