// 2025-07-25
class Solution {
 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> cnts(60, 0);
    for (int& t : time) {
      ++cnts[t % 60];
    }
    int result = 0;
    static vector<int> idxs {0, 30};
    for (int idx : idxs) {
      if (cnts[idx] >= 2) {
        if (cnts[idx] % 2 == 0) {
          result += cnts[idx] / 2 * (cnts[idx] - 1);
        } else {
          result += (cnts[idx] - 1) / 2 * cnts[idx];
        }
      }
    }
    for (int i = 1; i <= 29; ++i) {
      result += cnts[i] * cnts[60 - i];
    }
    return result;
  }
};
