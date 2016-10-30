// Copyright 2016 Qi Wang
// Date: 2016-10-30
class Solution {
 public:
  inline int pathSum(TreeNode* root, int sum) {
    return !root ? 0 : pathSumNotBegin(root, sum);
  }

 private:
  int pathSumNotBegin(TreeNode* root, int sum) const {
    return !root ? 0 : pathSumNotBegin(root->left, sum)
        + pathSumNotBegin(root->right, sum) + pathSumHasBegun(root, sum);
  }

  int pathSumHasBegun(TreeNode* root, int sum) const {
    return !root ? 0 : (root->val == sum) 
        + pathSumHasBegun(root->left, sum - root->val)
        + pathSumHasBegun(root->right, sum - root->val);
  }
};
