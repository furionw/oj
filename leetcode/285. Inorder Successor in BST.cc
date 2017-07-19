// Copyright 2017 Qi Wang
// Date: 2017-07-18
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* candidate = nullptr;
    return F(root, p, candidate);
  }

 private:
  TreeNode* F(TreeNode* root, TreeNode* target, TreeNode* candidate) const {
    if (root == target) {
      TreeNode* result = Leftmost(root->right);
      return nullptr != result ? result : candidate;
    } else if (root->val > target->val) {
      return F(root->left, target, root);
    } else {
      return F(root->right, target, candidate);
    }
  }

  TreeNode* Leftmost(TreeNode* root) const {
    if (nullptr == root) return nullptr;
    for (; nullptr != root->left; root = root->left) {}
    return root;
  }
};
