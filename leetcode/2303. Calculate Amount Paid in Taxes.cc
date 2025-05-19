// 2025-05-17
class Solution {
 public:
  double calculateTax(vector<vector<int>>& brackets, int income) {
    double result = 0;
    int prev = 0;
    // for (const auto& b : brackets) {
    for (int i = 0; i < brackets.size(); ++i) {
      const auto& b = brackets[i];
      if (income < b[0]) {
        result += (income - prev) * b[1] / 100.;
        break;
      } else {
        result += (b[0] - prev) * b[1] / 100.;
        prev = b[0];
      }
    }
    return result;
  }
};
