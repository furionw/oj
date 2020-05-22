// Copyright 2020 Qi Wang
// Date: 2020-04-18
class Solution {
  public int divide(int dividend, int divisor) {
    if (dividend == Integer.MIN_VALUE) {
      if (divisor == -1) {
        return Integer.MAX_VALUE;
      } else if ((divisor & 1)== 1) {
        return divide(Integer.MIN_VALUE + 1, divisor);
      } else {
        return divide(Integer.MIN_VALUE >> 1, divisor >> 1);
      }
    }
    boolean positive = true;
    if (dividend < 0) {
      dividend = -dividend;
      positive = !positive;
    }
    if (divisor < 0) {
      divisor = -divisor;
      positive = !positive;
    }
    int result = 0;
    while (dividend >= divisor) {
      int cnt = 1;
      int num = divisor;
      while ((num << 1) <= dividend) {
        num <<= 1;
        cnt <<= 1;
      }
      dividend -= num;
      result += cnt;
    }
    return positive ? result : -result;
  }
}
