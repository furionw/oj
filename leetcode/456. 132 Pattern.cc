// Copyright 2016 Qi Wang
// Refer to: http://bookshadow.com/weblog/2016/11/13/leetcode-132-pattern/
// Date: 2016-11-14
class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    if (nums.size() < 3) return false;
    multiset<int> numSet;
    for (int num : nums)
      numSet.insert(num);
    int min = INT_MAX;
    for (int num : nums) {
      numSet.erase(numSet.find(num));
      if (num <= min) {
        min = num;
      } else {
        auto it = numSet.upper_bound(min);
        if (it != numSet.end() && *it < num)
          return true;
      }
    }
    return false;
  }
};
