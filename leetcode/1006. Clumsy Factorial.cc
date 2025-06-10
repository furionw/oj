// 2025-06-09
class Solution {
 public:
  int clumsy(int n) {
    int result = 0;
    bool first = true;
    for (int i = n; i >= 1; ) {
      int elem = 1;
      if (i >= 4) {
        elem = i * (i - 1) / (i - 2);
        result = first ? elem : result - elem;
        result += i - 3;
        i -= 4;
      } else if (i >= 3) {
        elem = i * (i - 1) / (i - 2);
        result = first ? elem : result - elem;
        i -= 3;
      } else if (i >= 2) {
        elem = i * (i - 1);
        result = first ? elem : result - elem;
        i -= 2;
      } else {
        --i;
        result = first ? elem : result - elem;
      }
      first = false;
    }
    return result;
  }
};
