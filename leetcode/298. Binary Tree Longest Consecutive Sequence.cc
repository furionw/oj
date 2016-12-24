// Copyright 2016 Qi Wang
// Date: 2016-12-24
class Solution {
 public:
  int longestConsecutive(TreeNode* root) {
    return root ? dfs(root, 1) : 0;
  }

 private:
  // root is NOT nullptr
  int dfs(TreeNode *root, int depth) {
    int res = depth;
    if (root->left)
      res = max(res, dfs(root->left,
          root->val + 1 == root->left->val ? depth + 1 : 1));
    if (root->right)
      res = max(res, dfs(root->right,
          root->val + 1 == root->right->val ? depth + 1 : 1));
    return res;
  }
};
