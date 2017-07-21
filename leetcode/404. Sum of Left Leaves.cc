// Copyright 2017 Qi Wang
// Date: 2017-07-20
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    return Dfs(root, false);
  }

 private:
  int Dfs(TreeNode* root, bool is_left) const {
    if (nullptr == root) return 0;
    if (nullptr == root->left && nullptr == root->right) {
      return is_left ? root->val : 0;
    } else {
      return Dfs(root->left, true) + Dfs(root->right, false);
    }
  }
};
