// Copyright 2017 Qi Wang
// Date: 2017-10-26
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int result = 0;
    Dfs(root, &result);
    return result;
  }
 
 private:
  int Dfs(TreeNode* root, int* result) const {
    if (root == nullptr) return -1;
    int left = Dfs(root->left, result);
    int right = Dfs(root->right, result);
    *result = max(*result, left + right + 2);
    return max(left, right) + 1;
  }
};

// Date: 2017-08-04
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int result = 0;
    F(root, &result);
    return result;
  }
 
 private:
  int F(TreeNode* root, int* result) const {
    if (root == nullptr) return 0;
    int left = F(root->left, result);
    int right = F(root->right, result);
    *result = max(*result, left + right);
    return 1 + max(left, right);
  }
};

// Date: 2017-04-02
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    auto result = F(root);
    return max(result.first, result.second) - 1;
  }

 private:
  // first: longest path to its leaf, second: diameter of subroot
  pair<int, int> F(TreeNode* root) const {
    if (root == nullptr) return {0, 0};
    auto left = F(root->left);
    auto right = F(root->right);
    return {max(left.first, right.first) + 1,
        max(max(left.second, right.second), left.first + right.first + 1)};
  }
};
