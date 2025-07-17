// 2025-07-16
class Solution {
 public:
  int winningPlayerCount(int n, vector<vector<int>>& pick) {
    for (const auto& p : pick) {
      ++playerToPicks_[p[0]][p[1]];
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
      const auto& picks = playerToPicks_[i];
      for (const auto [_, cnt] : picks) {
        if (cnt >= i + 1) {
          ++result;
          break;
        }
      }
    }
    return result;
  }

 private:
  unordered_map<int,
      unordered_map<int, int>> playerToPicks_;
};
