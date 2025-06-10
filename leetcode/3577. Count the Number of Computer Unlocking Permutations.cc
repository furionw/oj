// 2025-06-09
class Solution {
 public:
  int countPermutations(vector<int>& complexity) {
    // return 0;
    int n = complexity.size();
    for (int i = 1; i < n; ++i) {
      if (complexity[i] <= complexity[0]) {
        return 0;
      }
    }
    constexpr static int kMod = 1e9 + 7;
    long long result = 1;
    for (int i = 2; i <= n - 1; ++i) {
      result = result * i % kMod;
    }
    return int(result);
  }
};
