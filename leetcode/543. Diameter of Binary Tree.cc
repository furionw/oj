// Copyright 2017 Qi Wang
// Date: 2017-04-02
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    auto result = F(root);
    return max(result.first, result.second) - 1;
  }

 private:
  // first: longest path to its leaf, second: diameter of subroot
  pair<int, int> F(TreeNode* root) const {
    if (root == nullptr) return {0, 0};
    auto left = F(root->left);
    auto right = F(root->right);
    return {max(left.first, right.first) + 1,
        max(max(left.second, right.second), left.first + right.first + 1)};
  }
};
