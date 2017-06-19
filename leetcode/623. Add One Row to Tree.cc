// Copyright 2017 Qi Wang
// Date: 2017-06-19
class Solution {
 public:
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    return F(root, v, d);
  }

 private:
  // d should be a positive number
  TreeNode* F(TreeNode* root, int v, int d) const {
    if (nullptr == root) return nullptr;
    if (1 == d) {
      auto result = new TreeNode(v);
      result->left = root;
      return result;
    } else if (2 == d) {
      auto left = new TreeNode(v);
      left->left = root->left;
      root->left = left;
      auto right = new TreeNode(v);
      right->right = root->right;
      root->right = right;
      return root;
    } else {
      root->left = F(root->left, v, d - 1);
      root->right = F(root->right, v, d - 1);
      return root;
    }
  }
};

// Date: 2017-06-18
class Solution {
 public:
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (1 == d) {
      auto result = new TreeNode(v);
      result->left = root;
      return result;
    } else {
      return F(root, v, d);
    }
  }

 private:
  TreeNode* F(TreeNode* root, int v, int d) const {
    if (nullptr == root) return nullptr;
    if (2 == d) {
      auto left = new TreeNode(v);
      left->left = root->left;
      root->left = left;
      auto right = new TreeNode(v);
      right->right = root->right;
      root->right = right;
      return root;
    } else {
      root->left = F(root->left, v, d - 1);
      root->right = F(root->right, v, d - 1);
      return root;
    }
  }
};
