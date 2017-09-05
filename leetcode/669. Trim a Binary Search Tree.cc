// Copyright 2017 Qi Wang
// Date: 2017-09-02
class Solution {
 public:
  TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (root == nullptr) return nullptr;
    if (root->val < L) {
      return trimBST(root->right, L, R);
    } else if (root->val > R) {
      return trimBST(root->left, L, R);
    } else {
      root->left = trimBST(root->left, L, R);
      root->right = trimBST(root->right, L, R);
      return root;
    }
  }
};
