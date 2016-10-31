// Copyright 2016 Qi Wang
// Date: 2016-10-31
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    inorder(root, k);
    return res;
  }
 private:
  void inorder(TreeNode *root, int& k) {
    if (root->left) inorder(root->left, k);
    if (--k == 0) res = root->val;
    if (root->right) inorder(root->right, k);
  }

  int res;
};
