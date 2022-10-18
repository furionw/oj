// Date: 2022-10-17
class Solution {
 public:
  bool sumOfNumberAndReverse(int num) {
    for (int i = 0; i <= num / 2; ++i) {
      if (reverse(i, num - i)) {
        return true;
      }
    }
    return false;
  }
  
 private:
  bool reverse(int n1, int n2) {
    int other = 0;
    // reverse the larger number intentionally
    for (; n2 > 0; n2 /= 10) {
      other = other * 10 + n2 % 10;
    }
    return n1 == other;
  }
};
