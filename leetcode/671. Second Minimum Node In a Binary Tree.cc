// Copyright 2017 Qi Wang
// Date: 2017-09-03
class Solution {
 public:
  int findSecondMinimumValue(TreeNode* root) {
    if (root == nullptr) return -1;
    smallest_ = root->val;
    F(root);
    return result_ == INT_MAX ? -1 : result_;
  }

 private:
  void F(TreeNode* root) {
    if (root == nullptr) return;
    if (smallest_ < root->val) {
      result_ = min(result_, root->val);
    }
    F(root->left);
    F(root->right);
  }

  int smallest_ = 0;
  int result_ = INT_MAX;
};
