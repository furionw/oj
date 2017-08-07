// Copyright 2017 Qi Wang
// Date: 2017-08-06
class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    return FindTarget(root, root, k);
  }
 
 private:
  bool FindTarget(TreeNode* cur, TreeNode* root, int k) const {
    if (cur == nullptr) return false;
    return (cur->val << 1 != k && Find(root, k - cur->val)) ||
           FindTarget(cur->left, root, k) || FindTarget(cur->right, root, k);
  }
 
  bool Find(TreeNode* root, int k) const {
    if (root == nullptr) {
      return false;
    } else if (root->val == k) {
      return true;
    } else if (root->val > k) {
      return Find(root->left, k);
    // root->val < k
    } else {
      return Find(root->right, k);
    }
  }
};
