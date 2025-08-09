// 2025-08-09
class Solution {
 public:
  void cleanRoom(Robot& robot) {
    // face up
    cleanRoom(robot, 0, 0, 0 /*d*/);
  }

 private:
  void cleanRoom(Robot& robot, int i, int j, int d) {
    robot.clean();
    visited_[i][j] = true;
    for (int dd = 0; dd < 4; ++dd) {
      int nextD = (d + dd) % 4;
      static vector<int> deltas {-1, 0, 1, 0, -1};
      int nextI = i + deltas[nextD];
      int nextJ = j + deltas[nextD + 1];
      if (!visited_[nextI][nextJ] && robot.move()) {
        cleanRoom(robot, nextI, nextJ, nextD);
        robot.turnLeft();
      } else {
        robot.turnRight();
      }
    }
    robot.turnRight();
    robot.turnRight();
    robot.move();
  }

  unordered_map<int, unordered_map<int, bool>> visited_;
};
