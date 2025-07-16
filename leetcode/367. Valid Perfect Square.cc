// 2025-07-15
class Solution {
 public:
  bool isPerfectSquare(int num) {
    long long l = 1, r = num;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (mid * mid >= num) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l * l == num;
  }
};
