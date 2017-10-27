// Copyright 2017 Qi Wang
// Date: 2017-10-26
// Question from nowcoder.com
// Case 1: [2, 1, 3]
// Case 2: [3, 2, 1, #, 4, #, 6]
class Solution {
 public:
  TreeNode* Convert(TreeNode* root) {
    if (root == nullptr) return nullptr;
    return Dfs(root).first;
  }
 
 private:
  pair<TreeNode*, TreeNode*> Dfs(TreeNode* root) const {
    pair<TreeNode*, TreeNode*> result {root, root};
    if (root->left != nullptr) {
      auto left = Dfs(root->left);
      left.second->right = root;
      root->left = left.second;
      result.first = left.first;
    }
    if (root->right != nullptr) {
      auto right = Dfs(root->right);
      right.first->left = root;
      root->right = right.first;
      result.second = right.second;
    }
    return result;
  }
};
