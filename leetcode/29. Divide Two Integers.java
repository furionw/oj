// Copyright 2020 Qi Wang
// Date: 2020-05-24
class Solution {
  public int divide(int dividend, int divisor) {
    if (divisor == -1) {
      return dividend == Integer.MIN_VALUE ? Integer.MAX_VALUE : -dividend;
    } else if (divisor == 1) {
      return dividend;
    } else if (dividend == Integer.MIN_VALUE) {
      if ((divisor & 1) == 1) {
        return divide(Integer.MIN_VALUE + 1, divisor);
      } else {
        return divide(Integer.MIN_VALUE >> 1, divisor >> 1);
      }
    } else if (divisor == Integer.MIN_VALUE) {
      return 0;
    }

    if (dividend < 0) {
      return -divide(-dividend, divisor);
    }
    if (divisor < 0) {
      return -divide(dividend, -divisor);
    }

    // Now, both dividend and divisor are positive numbers.
    int result = 0;
    while (dividend >= divisor) {
      int cnt = 1, subtract = divisor;
      for (; (dividend >> 1) >= subtract; subtract <<= 1) {
        cnt += cnt;
      }
      dividend -= subtract;
      result += cnt;
    }
    return result;
  }
}
