// 2025-07-16
class Solution {
 public:
  string winningPlayer(int x, int y) {
    int f1 = x;
    int f2 = y / 4;
    int f3 = min(f1, f2);
    return (f3 & 1 == 1) ? "Alice" : "Bob";
  }
};
