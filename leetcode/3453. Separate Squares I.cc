// 2025-05-04
class Solution {
 public:
  double separateSquares(vector<vector<int>>& squares) {
    map<int, double> incs;
    double target = 0;
    for (const auto& s : squares) {
      incs[s[1]] += s[2];
      incs[s[1] + s[2]] -= s[2];
      target += 1. * s[2] * s[2] / 2;
    }
    double alpha = 0;
    double acc = 0;
    for (auto it = incs.begin(); it != incs.end(); ++it) {
      auto next = it;
      ++next;
      alpha += it->second;
      if (alpha == 0) {
        continue;
      }
      double need = (target - acc) / alpha;
      if (need <= next->first - it->first) {
        return it->first + need;
      } else {
        acc += alpha * (next->first - it->first);
      }
    }
    return -1;
  }
};
