// Date: 2022-11-29
class Solution {
 public:
  int numberOfCuts(int n) {
    if (n == 1) {
      return 0;
    }
    double degree = 360. / n;
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
      double cur = degree * i;
      if (round(cur) >= 180) {
        cur -= 180;
      }
      s.insert(round(cur * 100));
    }
    return s.size();
  }
};
