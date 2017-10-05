// Copyright 2017 Qi Wang
// Date: 2017-10-05
class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
    if (root == nullptr) return nullptr;
    if (root == A || root == B) return root;
    auto* left = lowestCommonAncestor(root->left, A, B);
    auto* right = lowestCommonAncestor(root->right, A, B);
    return left != nullptr && right != nullptr
        ? root
        : (left != nullptr ? left : right);
  }
};
