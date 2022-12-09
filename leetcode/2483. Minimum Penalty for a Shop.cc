// Date: 2022-12-08
class Solution {
 public:
  int bestClosingTime(string customers) {
    int res = 0;
    int cur = 0;
    for (char c : customers) {
      cur += c == 'Y';
    }
    int penalty = cur;
    int close = 1;
    for (char c : customers) {
      // open door for the current hour
      cur += c == 'Y' ? -1 : 1;
      if (cur < penalty) {
        penalty = cur;
        res = close;
      }
      ++close;
    }
    return res;
  }
};
