// Date: 2022-10-31
class Solution {
 public:
  long long makeIntegerBeautiful(long long n, int target) {
    long long result = 0;
    for (long long i = 1; cal(n) > target; i *= 10) {
      int digit = n % 10;
      result += (10 - digit) * i;
      n /= 10;
      ++n;
    }
    return result;
  }
  
 private:
  int cal(long long n) {
    int cur = 0;
    for (long long tmp = n; tmp > 0; tmp /= 10) {
      cur += tmp % 10;
    }
    return cur;
  }
};
