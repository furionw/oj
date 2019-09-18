// Copyright 2019 Qi Wang
// Date: 2019-09-15
class Solution {
 public:
  bool isCousins(TreeNode* root, int x, int y) {
    auto left = foo(nullptr, root, 0, x);
    auto right = foo(nullptr, root, 0, y);
    return left.first == right.first && left.second != right.second;
  }

 private:
  pair<int, TreeNode*> foo(TreeNode* parent, TreeNode* root, int depth, int val) const {
    if (root == nullptr) {
      return make_pair(-1, nullptr);
    } else if (root->val == val) {
      return make_pair(depth + 1, parent);
    }
    auto left = foo(root, root->left, depth + 1, val);
    return left.first != -1 ? left : foo(root, root->right, depth + 1, val);
  } 
};
