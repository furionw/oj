// Copyright 2017 Qi Wang
// Date: 2017-04-07
class Solution {
 public:
  int TreeDepth(TreeNode* root) {
    return root == nullptr
        ? 0
        : max(TreeDepth(root->left), TreeDepth(root->right)) + 1;
  }
};

// Follow up
class Solution {
 public:
  bool IsBalanced_Solution(TreeNode* pRoot) {
    int placeholder;
    return IsBalanced(pRoot, placeholder);
  }

 private:
  bool IsBalanced(TreeNode* root, int& depth) const {
    if (root == nullptr) {
      depth = 0;
      return true;
    }
    int left, right;
    if (IsBalanced(root->left, left) && IsBalanced(root->right, right)
        && abs(left - right) <= 1) {
      depth = max(left, right) + 1;
      return true;
    }
    return false;
  }
};
