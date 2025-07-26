// 2025-07-25
class Solution {
 public:
  bool isRobotBounded(string instructions) {
    vector<int> deltas {0, 1, 0, -1, 0};
    int d = 0;
    int x = 0;
    int y = 0;
    for (char c : instructions) {
      cout << d << endl;
      if (c == 'G') {
        x += deltas[d];
        y += deltas[d + 1];
      } else if (c == 'R') {
        ++d;
        d %= 4;
      } else {
        --d;
        d = (d + 4) % 4;
      }
    }
    return (x == 0 && y == 0) || d != 0;
  }
};
