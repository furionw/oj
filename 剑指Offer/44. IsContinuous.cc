// Copyright 2017 Qi Wang
// Date: 2017-04-08
class Solution {
 public:
  bool IsContinuous(vector<int> numbers) {
    // trivial case
    if (numbers.empty()) return false;
    // non-trivial
    sort(numbers.begin(), numbers.end());
    int zero_cnt = count(numbers.begin(), numbers.end(), 0);
    if (zero_cnt >= numbers.size() - 1) return true;
    int prev = numbers[zero_cnt];
    for (int i = zero_cnt + 1; i < numbers.size(); ++i) {
      // identical numbers
      if (numbers[i] == prev) return false;
      // using zeros to fill the gap between current and previous numbers
      if (numbers[i] != prev + 1) {
        if (zero_cnt >= numbers[i] - (prev + 1)) {
          zero_cnt -= numbers[i] - (prev + 1);
        } else {
          // unsufficient zero
          return false;
        }
      }
      // update "prev" number
      prev = numbers[i];
    }
    return true;
  }
};
