#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cassert>

using namespace std;

class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    // Error: Ill-formed input
    if (input.empty()) return vector<int>();

    // Trivial case: input only has exactly one element

    // Method 1
    if (all_of(input.begin(), input.end(), [this](char c) { return !isOp(c); }))
    // Method 2, which compiles wrong.
    if (! any_of(input.begin(), input.end(), &Solution::isOp))
      return vector<int>(1, stoi(input));

    // Non-trivial case
    vector<int> res;
    for (size_t i = 0; i < input.size(); ++i)
      if (isOp(input[i])) {
        auto leftNums = diffWaysToCompute(input.substr(0, i));
        auto rightNums = diffWaysToCompute(input.substr(i + 1));
        for (int lhs: leftNums)
          for (int rhs: rightNums)
            res.push_back(eval(input[i], lhs, rhs));
      }
    return res;
  }

 private:
  inline bool isOp(char c) {
    return c == '+' || c == '-' || c == '*';
  }

  inline int eval(char op, int lhs, int rhs) {
    switch (op) {
      case '+':
        return lhs + rhs;
      case '-':
        return lhs - rhs;
      case '*':
        return lhs * rhs;
      default:
        assert(false);
    }
  }
};
