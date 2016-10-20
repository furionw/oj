// Copyright 2016 Qi Wang
// Taught by Ming Lin
// Date: 2016-09-26
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int less = 0, greater = numbers.size() - 1;
    for (int sum = numbers[less] + numbers[greater]; sum != target;
        sum = numbers[less] + numbers[greater]) {
      if (sum > target) {
        --greater;
      } else {
        ++less;
      }
    }
    return vector<int>{less + 1, greater + 1};
  }
};