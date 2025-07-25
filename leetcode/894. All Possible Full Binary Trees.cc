// 2025-07-23
class Solution {
 public:
  vector<TreeNode*> allPossibleFBT(int n) {
    // Prunning
    // According to the Editorial, a full tree always has odd number of nodes.
    // That is, tree node + even children.
    if (n % 2 == 0) {
      return {};
    }
    if (n == 1) {
      return {new TreeNode(0, nullptr, nullptr)};
    }
    vector<TreeNode*> result;
    // +=2 instead of 1 for prunning
    for (int i = 1; i <= n - 2; i += 2) {
      auto lefts = allPossibleFBT(i);
      // (n - 1) - i > 0. i.e. rights won't be empty
      auto rights = allPossibleFBT(n - 1 - i);
      for (auto l : lefts) {
        for (auto r : rights) {
          result.push_back(new TreeNode(0, l, r));
        }
      }
    }
    return result;
  }
};
