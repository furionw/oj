// Copyright 2017 Qi Wang
// Date: 2017-10-03
// Case 1: [1, 2, 3, 4], 5
// Case 2: [-2, 3, 1, 2], -1
class Solution {
 public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> num_to_idx_map;
    for (int i = 0; i < numbers.size(); ++i) {
      int num2 = target - numbers[i];
      if (num_to_idx_map.count(num2) == 1) {
        return {num_to_idx_map[num2] + 1, i + 1};
      } else if (num_to_idx_map.count(numbers[i]) == 0) {
        num_to_idx_map[numbers[i]] = i;
      }
    }
    return {0, 0};  // comfort the compiler
  }
};
