// Copyright 2016 Qi Wang
// Date: 2016-10-06
class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    if (nums.empty()) return res;
    int candidate1, candidate2;
    int cnt1 = 0, cnt2 = 0;
    for (int num : nums)
      if (candidate1 == num) {
        ++cnt1;
      } else if (candidate2 == num) {
        ++cnt2;
      } else if (cnt1 == 0) {
        candidate1 = num;
        ++cnt1;
      } else if (cnt2 == 0) {
        candidate2 = num;
        ++cnt2;
      } else {
        --cnt1;
        --cnt2;
      }
    cnt1 = cnt2 = 0;
    for (int num : nums) {
      cnt1 += num == candidate1 ? 1 : 0;
      cnt2 += num == candidate2 ? 1 : 0;
    }
    if (cnt1 > nums.size() / 3)
      res.push_back(candidate1);
    if (cnt2 > nums.size() / 3 && candidate1 != candidate2)
      res.push_back(candidate2);
    return res;
  }
};
