// Copyright 2016 Qi Wang
// Date: 2016-12-31
class Solution {
 public:
  int closestValue(TreeNode* root, double target) {
    if (root == nullptr) return 0;
    int res = root->val;
    closestValue(root, target, res);
    return res;
  }

 private:
  void closestValue(TreeNode* root, double target, int& res) {
    if (fabs(root->val - target) < fabs(res - target))
      res = root->val;
    if (root->left != nullptr && target < root->val)
      closestValue(root->left, target, res);
    if (root->right != nullptr && target > root->val)
      closestValue(root->right, target, res);
  }
};

// Date: 2016-12-30
class Solution {
 public:
  int closestValue(TreeNode* root, double target) {
    if (root == nullptr) return 0;
    int res = root->val;
    closestValue(root, target, res);
    return res;
  }

 private:
  void closestValue(TreeNode* root, double target, int& res) {
    if (fabs(root->val - target) < fabs(res - target))
      res = root->val;
    if (root->left != nullptr) closestValue(root->left, target, res);
    if (root->right != nullptr) closestValue(root->right, target, res);
  }
};
