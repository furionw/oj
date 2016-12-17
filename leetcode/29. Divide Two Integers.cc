// Copyright 2016 Qi Wang
// Date: 2016-12-17
class Solution {
 public:
  int divide(int dividend, int divisor) {
    bool negative = (dividend > 0 && divisor < 0)
        || (dividend < 0 && divisor > 0);
    uint64_t a = abs(static_cast<int64_t>(dividend)),
        b = abs(static_cast<int64_t>(divisor)), quotient = 0;
    while (a >= b) {
      int64_t sum = b, cnt = 1;
      while (a >= sum << 1) {
        sum <<= 1;
        cnt <<= 1;
      }
      a -= sum;
      quotient += cnt;
    }
    if (!negative && quotient == static_cast<uint64_t>(INT_MAX) + 1)
      return INT_MAX;
    return negative ? -quotient : quotient;
  }
};

// Date: 2014-06
class Solution {
 public:
  int divide(int dividend, int divisor) {
    bool negative = (dividend < 0 && divisor > 0)
        || (dividend > 0 && divisor < 0);
    // cast to long long first, or we'll get overflow when abs(-2147483648),
    // since int is limited to 2147483647
    int64_t a = abs(static_cast<int64_t>(dividend)),
        b = abs(static_cast<int64_t>(divisor)), quotient = 0;
    while (a >= b) {
      long long sum = b;
      int64_t cnt = 1;
      while (sum + sum <= a) {
        sum += sum;
        cnt += cnt;
      }
      a -= sum;
      quotient += cnt;
    }
    if (!negative && quotient == static_cast<int64_t>(INT_MAX) + 1)
      return INT_MAX;
    return negative ? -quotient : quotient;
  }
};
