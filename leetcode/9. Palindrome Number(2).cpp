class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;

    int base = 1;
    for (int num = x; num / 10 > 0; num /= 10)
      base *= 10;

    while (x != 0)
      if (x / base != x % 10) {
        return false;
      } else {
        x = (x % base) / 10;
        base /= 100;
      }

    return true;
  }
};
