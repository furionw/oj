// 2025-07-17
class Solution {
 public:
  int fib(int n) {
    if (n == 0) {
      return 0;
    }

    int first = 0;
    int second = 1;
    for (int i = 2; i <= n; ++i) {
      first += second;
      swap(first, second);
    }
    return second;
  }
};
