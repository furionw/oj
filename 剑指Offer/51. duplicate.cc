// Copyright 2017 Qi Wang
// Date: 2017-04-16
class Solution {
 public:
  bool duplicate(int numbers[], int length, int* duplication) {
    // invalid parameter
    if (length == 0 || duplication == nullptr) return false;
    // invalid array
    for (int i = 0; i < length; ++i)
      if (numbers[i] < 0 || numbers[i] >= length)
        return false;
    for (int i = 0; i < length; ++i) {
      while (numbers[i] != i) {
        if (numbers[numbers[i]] == numbers[i]) {
          *duplication = numbers[i];
          return true;
        } else {
          swap(numbers[i], numbers[numbers[i]]);
        }
      }
    }
    return false;
  }
};
