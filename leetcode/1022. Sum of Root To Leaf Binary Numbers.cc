// Copyright 2019 Qi Wang
// Date: 2019-09-14
class Solution {
 public:
  int sumRootToLeaf(TreeNode* root) {
    return sum_root_to_leaf(root, 0);
  }

 private:
  int sum_root_to_leaf(TreeNode* root, int parent) const {
    if (root == nullptr) {
      return 0;
    }
    int cur = root->val + parent * 2;
    return root->left == nullptr && root->right == nullptr
        ? cur
        : sum_root_to_leaf(root->left, cur) + sum_root_to_leaf(root->right, cur);
  }
};
