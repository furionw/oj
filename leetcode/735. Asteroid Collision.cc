// 2025-07-18
class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;
    for (int a : asteroids) {
      if (a > 0) {
        result.push_back(a);
      } else {
        while (true) {
          if (result.empty() || result.back() < 0) {
            result.push_back(a);
            break;
          }
          if (result.back() < -a) {
            result.pop_back();
          } else if (result.back() == -a) {
            // `back` exploded
            result.pop_back();
            // `a` exploded too. break
            break;
          } else {
            // `a` exploded. break
            break;
          }
        }
      }
    }
    return result;
  }
};
