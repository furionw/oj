// Date: 2022-11-26
class Solution {
 public:
  int pivotInteger(int n) {
    if (n == 1) {
      return 1;
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      sum += i;
    }
    int leftSum = 1;
    for (int i = 2; i <= n; ++i) {
      leftSum += i;
      sum -= i - 1;
      if (sum == leftSum) {
        return i;
      }
    }
    return -1;
  }
};
