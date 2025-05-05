// 2025-05-03
class Solution {
 public:
  int maxProduct(int n) {
    map<int, int> cnts;
    for (; n > 0; n /= 10) {
      ++cnts[n % 10];
    }
    auto it = cnts.rbegin();
    if (it->second > 1) {
      return it->first * it->first;
    } else {
      int result = it->first;
      ++it;
      return result * it->first;
    }
  }
};
