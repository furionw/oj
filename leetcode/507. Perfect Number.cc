// Copyright 2017 Qi Wang
// Date: 2017-06-08
class Solution {
 public:
  bool checkPerfectNumber(int num) {
    if (num <= 0) return false;
    int sum = 1;
    for (int i = 2; i < sqrt(num); ++i)
      if (num % i == 0) sum += i + num / i;
    if (num == sqrt(num) * sqrt(num)) sum += sqrt(num);
    return sum == num;
  }
};
