// Copyright 2019 Qi Wang
// Date: 2019-09-17
class Solution {
 public:
  int rangeSumBST(TreeNode* root, int L, int R) {
    if (root == nullptr) {
      return 0;
    } 
    return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) +
           (root->val >= L && root->val <= R ? root->val : 0);
  }
};
