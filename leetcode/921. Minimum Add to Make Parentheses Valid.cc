// 2025-07-24
class Solution {
 public:
  int minAddToMakeValid(string s) {
    int balance = 0;
    int result = 0;
    for (char c : s) {
      if (c == '(') {
        ++balance;
      } else {
        if (balance > 0) {
          --balance;
        } else {
          ++result;
        }
      }
    }
    return result + balance;
  }
};
